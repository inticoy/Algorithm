#!/bin/bash
set -e

# 임시 파일 생성
TABLE_FILE="table.md"

# 영어 헤더로 표 작성 (First Solved Date와 Last Solved Date 열 추가)
echo "| First Solved Date | Last Solved Date | Number | Title |" > $TABLE_FILE
echo "| --- | --- | --- | --- |" >> $TABLE_FILE

# 현재 디렉토리의 서브 폴더들 순회
for dir in */ ; do
  # 폴더 이름에서 마지막 슬래시 제거
  folder="${dir%/}"
  
  # 폴더 이름이 숫자-문자열 형식인지 확인 (예: 0443-string-compression)
  if [[ "$folder" =~ ^[0-9]+- ]]; then
    # 문제 번호: 첫번째 하이픈 전까지
    problem_number=$(echo "$folder" | cut -d '-' -f 1)
    # 제목: 첫번째 하이픈 이후의 나머지
    title=$(echo "$folder" | cut -d '-' -f 2-)
    
    # 각 폴더 내 파일들 중 가장 첫 커밋 날짜를 "First Solved Date"로 사용
    first_solved=$(git log --reverse --date=format:'%Y.%m.%d' --format="%cd" -- "$folder" | head -n 1)
    if [ -z "$first_solved" ]; then
      first_solved="N/A"
    fi
    
    # 해당 폴더 내 마지막 커밋 날짜를 "Last Solved Date"로 사용
    last_solved=$(git log -1 --date=format:'%Y.%m.%d' --format="%cd" -- "$folder")
    if [ -z "$last_solved" ]; then
      last_solved="N/A"
    fi
    
    # 표에 한 줄 추가
    echo "| $first_solved | $last_solved | $problem_number | $title |" >> $TABLE_FILE
  fi
done

# README.md 파일 내에 테이블을 삽입할 영역을 미리 지정해둡니다.
# 예를 들어, README.md에 아래와 같이 마커를 넣어두세요.
#
# <!-- START TABLE -->
# (기존 내용은 무시됨)
# <!-- END TABLE -->
#
# 스크립트는 이 영역을 새로 생성한 테이블로 대체합니다.

README_FILE="README.md"
START_MARKER="<!-- START TABLE -->"
END_MARKER="<!-- END TABLE -->"

# 마커가 존재하는지 확인
if ! grep -q "$START_MARKER" "$README_FILE"; then
  echo "README.md에 '$START_MARKER' 마커가 없습니다. 추가 후 다시 실행하세요."
  exit 1
fi

if ! grep -q "$END_MARKER" "$README_FILE"; then
  echo "README.md에 '$END_MARKER' 마커가 없습니다. 추가 후 다시 실행하세요."
  exit 1
fi

# 마커 전후의 내용을 분리하여 새 README.md 생성
# (1) 시작 마커 전까지의 내용
head -n $(grep -n "$START_MARKER" "$README_FILE" | head -n1 | cut -d: -f1) "$README_FILE" > README_new.md
# (2) 테이블 내용 삽입
cat $TABLE_FILE >> README_new.md
# (3) 종료 마커부터 파일 끝까지의 내용 추가
grep -n "$END_MARKER" "$README_FILE" | head -n1 | cut -d: -f1 | xargs -I {} tail -n +{} "$README_FILE" >> README_new.md

# 새 파일로 덮어쓰기
mv README_new.md "$README_FILE"

echo "README.md 업데이트 완료."
