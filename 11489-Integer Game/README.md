# 11489-Integer Game

GAME RULE: 給定一個數N(ex:1234) 兩個人 S AND T , S先攻

每個人一回合可以從N抽走一個數字(ex:抽走1-->變成234)

但抽走一數之後的N剩下的數相加必需被三整除(ex: 2+3+4 = 9)

如果輪到自己的回合沒辦法抽走任何一數使n達成條件就輸了

現在INPUT一個N 求最後贏的是S還是T


<font color=#FF0000>KEY POINT: n拿掉一個數必定相加是三的倍數</font>

N分為兩種狀況(假設total = n每個位元的數相加):

	設 mod3 = n內三的倍數個數
	total mod 3 == 0 :	
		IF mod3 is even : S WIN 
		IF mod3 is odd  : T WIN

	total mod 3 != 0 :
		從n中拿出一個數使total mod 3 == 0 ,如果無法辦到則 T WIN
		IF mod3 is even : T WIN 
		IF mod3 is odd  : S WIN
