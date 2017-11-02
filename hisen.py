import colorama
from colorama import Fore, Back, Style
colorama.init(autoreset=True)

import matplotlib.pyplot as plt

from tqdm import tqdm

import numpy as np			 #結果表示に使う


#############################################
#       線形の計算法から非線形の計算法へ

#           1.陽的な数値粘性項の付加         < 今回使っていません

#           2.高解像度風上法                 < 今回使いました
#############################################


################## domein ###################

#       一次精度

_ryki = 8

x = [j-_ryki for j in range(_ryki * 2)]

u = [0 for j in range(_ryki * 2)]
for j in range(_ryki):
    u[j]= 1

plt.plot(x,u)

unew = [0 for j in range(_ryki * 2)]

#       f((j-1)/2)

fm = [0 for j in range(_ryki * 2)]

#       f((j+1)/2)

fp = [0 for j in range(_ryki * 2)]
#############################################


################ input ######################

#		例外処理 for input

def parrot_no_v(q):
	assert -1 <= q <= 1, Fore.RED + "x shulde be between -1 and 1"
def parrot_ponum(q):
	assert 0 <= q, Fore.RED + "x shulde be a positive number"

#       input

try:
	v = float(input("クーラン数vを決めて下さい。(-1~1): "))
except ValueError:
	print(Fore.RED + "[Error]:数値を入力して下さい")
	sys.exit()
parrot_no_v(v)

try:
	times = int(input("計算回数を決めて下さい。: "))
except ValueError:
	print(Fore.RED + "[Error]:数値を入力して下さい")
	sys.exit()
parrot_ponum(times)
############################################


############### compute ####################

#		まずは一次精度で。

for n in range(times):
    for j in range(1,_ryki * 2 - 1):

#       非保存式による差分化
#       線形の計算法から非線形の計算法へ

#       cmpute uc and um and up
        uc = u[j]
        um = u[j - 1]
        up = u[j + 1]

#       f((j-1)/2)

#       if v > 0 : fm[j] = 0.5 * u[j - 1] ** 2
#       if v < 0 : fm[j] = 0.5 * u[  j  ] ** 2

        uc1 = 0.5 * (v - abs(v)) * uc / abs(v)
        uc2 = 0.5 * uc1 ** 2
        um1 = 0.5 * (v + abs(v)) * um / abs(v)
        um2 = 0.5 * um1 ** 2
        fm[j] = uc2 + um2

#       f((j+1)/2)

#       if v > 0 : fm[j] = 0.5 * u[  j  ] ** 2
#       if v < 0 : fm[j] = 0.5 * u[j + 1] ** 2

        up1 = 0.5 * (v - abs(v)) * up / abs(v)
        up2 = 0.5 * up1 ** 2
        uc1 = 0.5 * (v + abs(v)) * uc / abs(v)
        uc2 = 0.5 * uc1 ** 2
        fp[j] = up2 + uc2

#       u(n + 1) >> unew[j]

#       if v > 0 : unew[j] = u[j] - v * 0.5 * (u[  j  ] ** 2 - u[j - 1] ** 2)
#       if v < 0 : unew[j] = u[j] - v * 0.5 * (u[j + 1] ** 2 - u[  j  ] ** 2)

        unew[j]  = u[j] - v * (fp[j] - fm[j])

    for j in range(1,_ryki * 2 - 1):
        u[j]=unew[j]

    plt.plot(x,u)
    print(np.round(u,1))
plt.show()
###########################################
