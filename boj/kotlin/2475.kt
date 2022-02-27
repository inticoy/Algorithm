package boj

fun main() {
    var total = 0
    var line = readLine()!!
        .split(" ")
        .map { it.toInt() }
    for (number in line) total += number * number
    print(total % 10)

}