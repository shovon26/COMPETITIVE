private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main()
{
    var t: Int = readLine()!!.toInt()
    while (t>0){
        var (n, k) = readInts()
       var n0 = n/(1+k+k*k+k*k*k)
        var n1=n0
        var n2=n1*k
        var n3 =n2*k
        var n4=n3*k
        println("${n1} ${n2} ${n3} ${n4}")
        t--
    }
}
