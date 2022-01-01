//Problem Name : Excel Sheet Column Number

using System;
using System.Collections.Generic;
namespace HelloProject {
	public class Solution {
	    public string TitleToNumber(int number) {
	        string ans = "";
	        while(number > 0){
				int cur = number % 26;
				if(cur == 0){
					cur = 26;
					number /= 26;
					number--;
				}
				else number /= 26;
				char ch = (char)(cur + 'A' - 1);
				ans += ch;
			}
			string ret = "";
			int len = ans.Length;
			for(int i=len-1; i>=0; i--) ret += ans[i];
			return ret;
	    }
	}
	class Program {
		static void Main(string[] args) {
			int num = 703;
			Solution ob = new Solution();
			string ans = ob.TitleToNumber(num);
			Console.WriteLine(ans);
		}
	}
}
