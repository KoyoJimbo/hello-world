import colorama
from colorama import Fore, Back, Style
colorama.init(autoreset=True)

from tqdm import tqdm
import matplotlib.pyplot as plt
from numpy.random import *
import sys

#計算数
_sen = 8
count =0
########################################################################
#差分スキームたち
##左辺はn+1回目、右辺はn回目
def FTCS(st,v):
	st[t + 1][i + 1]=st[t][i + 1]-st[t][i + 2] * v / 2 + st[t][i] * v / 2

def one_dim(st,v):
	st[t + 1][i + 1] = st[t][i + 1] * (1 - v) + st[t][i] * v

def LW(st,v):
	st[t + 1][i + 1] = st[t][i + 1] * (1 - v ** 2) + st[t][i + 2] * (v ** 2 - v) / 2 + st[t][i] * (v+v ** 2) / 2

def Lax(st,v):
	st[t + 1][i + 1] = st[t][i + 2] * (1 - v) / 2 + st[t][i] * (1 + v) / 2

def one_preci(st,v):
	if c == 1:
		st[t + 1][i + 1]=st[t][i + 1] * (1 - v) + st[t][i] * v
	elif c == 2:
		st[t + 1][i + 1]=st[t][i + 1] + v / 2 * ( st[t][i + 2] - st[t][i] ) + v / 2 * ( st[t][i + 2] - 2 * st[t][i + 1] + st[t][i] )

def LF(st,v,t):
	if t == 0:
		st[t + 1][i + 1] = st[t][i] - v * (st[t][i + 2] - st[t][i])
	else:
		st[t + 1][i + 1]=st[t - 1][i + 1] - v * (st[t][i + 2] - st[t][i])
############################################################################

############################################################################
##plot.titleの決定
def FTCS_title():
	plt.title("FTCS($v = {:.3f}$)".format(v))
def one_dim_title():
	plt.title("1-dimention upwind($v = {:.3f}$)".format(v))
def LW_title():
	plt.title("Lax-Wendroff($v = {:.3f}$)".format(v))
def Lax_title():
	plt.title("Lax($v = {:.3f}$)".format(v))
def one_preci_title():
	plt.title("1-order upwind($v = {:.3f}$)".format(v))
def LF_title():
	plt.title("Leap-Frog($v = {:.3f}$)".format(v))
###########################################################################

###########################################################################
#例外処理
def parrot_no_scheme(x):
	assert 1 <= x <= 6,Fore.RED + "x is not between 1 and 6"
	print(Fore.YELLOW+"input number is"+Fore.LIGHTWHITE_EX+":"+ Fore.BLUE + str(x))
def parrot_no_seido(x):
	assert 1 <= x <= 3, Fore.RED + "x is not between 1 and 2"
	print(Fore.YELLOW+"input number is"+Fore.LIGHTWHITE_EX+":"+ Fore.BLUE + str(x))
def parrot_no_v(x):
	assert 0 <= x <= 1, Fore.RED + "x is not between 0 and 1"
	print(Fore.YELLOW+"input number is"+Fore.LIGHTWHITE_EX+":"+ Fore.BLUE + str(x))
def parrot_no_c(x):
	assert 1 <= x <= 2, Fore.RED + "x is not between 1 and 2"
	print(Fore.YELLOW+"input number is"+Fore.LIGHTWHITE_EX+":"+ Fore.BLUE + str(x))
###########################################################################

print("1--自動\n2--手動")
print("'自動'はランダムに指定回 v を設定し、計算を行います。\n厳密解との差の二乗和が最小のグラフを返します。")
try:
	how_use = int(input("計算法を入力して下さい。( 1 ~ 2 の整数 ): "))
except ValueError:
	print(Fore.RED + "[Eroor]:整数を入力して下さい")
	sys.exit()
parrot_no_c(how_use )

if how_use == 1:
	try:
		times = int(input("計算回数を指定して下さい。: "))
		print(Fore.YELLOW+"input number is"+Fore.LIGHTWHITE_EX+":"+ Fore.BLUE + str(times))

	except ValueError:
		print(Fore.RED +"[Error]:整数を入力して下さい")
		sys.exit()
elif how_use == 2:
	times = 0



#はじめに画面に写し出されるもの
print("1--1次風上差分\n2--FTCS\n3--Lax-wendroff\n4--Lax\n5--1次精度風上差分\n6--Leap-Frog")
if how_use != 1:
	print("* 1 ~ 5 は三次精度まで, 5 は c < 0 の時の計算を行えます。")
try:
	s = int(input("スキームを決定して下さい。( 1 ~ 6 の整数 ): "))
except ValueError:
	print(Fore.RED + "[Error]:整数を入力して下さい")
	sys.exit()

parrot_no_scheme(s)

if how_use == 2:
	if s == 2 or s == 3 or s == 4 or s == 5:
		try:
			seido = int(input("精度を指定してください。(1 ~ 3 の整数):"))
		except ValueError:
			print(Fore.RED + "[Error]:整数を入力して下さい")
			sys.exit()
		parrot_no_seido(seido)
	elif s == 1 or s == 6:
		seido = 1
	try:
		v = float(input("クーラン数vを決めて下さい。(0~1): "))
	except ValueError:
		print(Fore.RED + "[Error]:数値を入力して下さい")
		sys.exit()
	parrot_no_v(v)
else:
	seido = 1
###########################################################################
if s == 5:
	print("1--:c>0\n2--:c<0")
	try:
		c = int(input("c"+"の正負を決定して下さい。: "))
	except ValueError:
		print(Fore.RED + "[Error]:整数を入力して下さい")
		sys.exit()
	parrot_no_c(c)
###########################################################################
###########################################################################
###########################################################################
for count in tqdm(range(times + 1)):
#while(count <= times):
	print(Fore.CYAN + "------------------------------------------------------------------------------------")
	if how_use == 1:
		if count != times or count == 0:
			v = rand()
			if count != 0:
				min_dic = min(dic)
				print("只今の最小値："+Fore.MAGENTA+str(min_dic))
		else:
			v = dic[min(dic)]
#一次精度ｘ軸
	x1 = [j-_sen for j in range(_sen * 2)]#x軸の値の設定 x = -6 ~ 5

#二次精度ｘ軸
	x2 = [j - _sen * 2 for j in range(_sen * 2 * 2)]#x軸の値の設定x =-12~11
	for j in range(_sen * 2 ):
		x2[j*2] = x1[j]
		x2[j*2 + 1] = (x1[j]+x1[j]+1) * 0.5
	if seido == 2:
		print("x2: "+str(x2))

#三次精度ｘ軸
	x3 = [j - _sen * 2 for j in range(_sen * 2 * 2 * 2 -2)]#x軸の値の設定x =-12~11
	for j in range(_sen * 2 * 2 - 1):
		x3[j * 2] = x2[j]
		x3[j * 2 + 1] = (x2[j] + x2[j + 1]) * 0.5
	if seido == 3:
		print("x3: "+str(x3))

	"""配列初期値
	when sen = 6
	0   1   2  3  4   5      6     7 8...     12

	0  12 3 4 567 89  10 11  12               24

	-6 -5  -4  -3 -2 -1      0                 6      x軸(j-sen)　
	"""
#初期値として波の高さがx=-1まで1、x=0からは0となるようにy軸の値を2次元配列ｓｔの０行目に代入
	st = [[0 for j in range(_sen*2)] for i in range(_sen)]
	for i in range(_sen):
		for j in range(_sen):
			st[i][j]= 1

#sl is going to be used when show right answer
	sl = [[0 for j in range(_sen*2)] for i in range(_sen)]
	for i in range(_sen):
	  	for j in range(_sen):
		 	 sl[i][j]= 1

#２次元配列であるstの０行目を１次元配列に直し、y1としてプロットする
#一次精度
	y1 = [0 for j in range(_sen*2)]
	for j in range (_sen*2):
		y1[j]=st[0][j]

	plt.plot(x1,y1) #初期値プロット

#二次精度 
	if seido == 2 or seido == 3:
		y2 = [0 for j in range(_sen * 2 * 2)]
		for j in range (_sen*2 - 1 ):
			y2[j * 2] = st[0][j]
			y2[j * 2 + 1] = 0.5 * (st[0][j] + st[0][j + 1])


#三次精度
	if seido == 3:
		y3 = [0 for j in range(_sen * 2 * 2 * 2 - 2)]
		for j in range (_sen * 2 * 2 - 1):
			y3[j * 2] = y2[j]
			y3[j * 2 + 1] = 0.5 * (y2[j] + y2[j + 1])



#1回目以降
	for t in range(_sen-2):
		for i in range(_sen*2-2):
			##FTCS
			if s == 2:
				FTCS(st,v)
			##1次風上差分
			elif s == 1:
				one_dim(st,v)
			##Lax-wendroff
			elif s == 3:
				LW(st,v)
			##Lax
			elif s == 4:
				Lax(st,v)
			##1次精度風上差分
			elif s == 5:
				one_preci(st,v)
			##Leap-Frog
			elif s == 6:
				LF(st,v,t)
		if seido == 1:
			#n+1回目の値をy1に再代入しy1をプロットする。
			for j in range(_sen*2):
				y1[j]=st[t][j]
			#insted
		elif seido == 2 or seido == 3:
			for j in range(_sen*2 - 1):
				y2[j*2]=st[t][j]
				if s == 2:#FTCS
					y2[j * 2 + 1] = 0.5 * ( st[t][j] + st[t][j+1] )
				elif s == 3:#Lax-wendroff
					y2[j * 2 + 1] = 0.5 * ( st[t][j] * (1 + v) + st[t][j + 1] * (1 - v) )
				elif s == 4:#Lax
					y2[j * 2 + 1] = 0.5 * ( st[t][j] * (1 + 1 / v) + st[t][j + 1] * (1 - 1 / v) )
				elif s == 5:#1-preci up wind
					if c == 1:
						y2[j * 2 + 1] = st[t][j]
					elif c == 2:
						y2[j * 2 + 1] = st[t][j + 1]
			if seido == 3:
				for j in range(_sen*2*2-1):
					y3[j*2] = y2[j]
					if s == 2:#FTCS
						y3[j * 2 + 1] = 0.5 * ( y2[j] + y2[j + 1] )

					elif s == 3:#Lax-wendroff
						y3[j * 2 + 1] = 0.5 * ( y2[j] * (1 + v) + y2[j + 1] * (1 - v) )

					elif s == 4:#Lax
						y3[j * 2 + 1] = 0.5 * ( y2[j] * (1 + 1 / v) + y2[j + 1] * (1 - 1 / v) )

					elif s == 5:#1-preci up wind
						if c == 1:
							y3[j * 2 + 1] = y2[j]
						elif c == 2:
							y3[j * 2 + 1] = y2[j + 1]

#0   1   2   3   4   5   6   7   8
#0 1 2 3 4 5 6 7 8 9 10
#i   i   i   i   i   i 
#0123456789
		if how_use == 2 or count == times or seido != 1:
			if seido == 1:
				p1, = plt.plot(x1,y1,color='blue')
			elif seido == 2:
			 	plt.plot(x2,y2,color='red')
			elif seido == 3:
				plt.plot(x3,y3,color='green')

	if seido == 1:
		print("y:"+str(y1))
	elif seido == 2:
		print("y"+str(y2))
	elif seido == 3:
		print("y"+str(y3))

	print("クーラン数:"+str(v))


#y1を初期値にもどす。
	for j in range (_sen*2):
		y1[j]=st[0][j]



	if seido == 1:
		u = 0
		v_one = 1
		#厳密解
		for t in range(_sen-2):
			for i in range(_sen*2-2):
				sl[t + 1][i + 1]=sl[t][i + 1] * (1 - v_one) + sl[t][i] * v_one
			#n+1回目の値をy1に再代入しy1をプロットする。
			for j in range(_sen*2):
				y1[j]=sl[t][j]
				u += (st[t][j]-sl[t][j]) ** 2
			if how_use == 1 or count == times:
				p2, = plt.plot(x1,y1,color='pink')
		print("厳密解との差の二乗和:" + str(u))
		if count < times:
			print("カウント"+ str(count+1))
		else:
			print(Fore.MAGENTA+ str(times)+"回の中計算の中で最も差が小さかったグラフ")
			print(Style.RESET_ALL)
		if count == 0:
			dic = {u:v}
		else:
			dic.update({u:v})
	count += 1
	print(Fore.CYAN + "------------------------------------------------------------------------------------")
	if how_use == 2 or seido != 1:
		break
#123567（ただのメモ）
#654310
#1 2 3 4 5 6 7 8
# 910111213141516


"""
下はplt.titleを選択
"""
##1次風上差分
if s == 1:
	one_dim_title()
elif s == 2:
	FTCS_title()
##Lax-wendroff
elif s == 3:
	LW_title()
##Lax
elif s == 4:
	Lax_title()
##1次精度風上差分
elif s == 5:
	one_preci_title()
##Leap-Frog
elif s == 6:
	LF_title()
if seido == 1 and how_use == 2:
	plt.legend([p1, p2],["The difference","Exact solution"])
plt.show()

#filename = "output.png"
#plt.savefig(filename)
