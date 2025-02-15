#https://www.naukri.com/code360/problems/total-salary_893200

from collections import *
from math import *

def totalSalary(basic, grade):

	# Write your code here.
	allowance=[1700,1500,1300]
	hrd=basic*0.2
	da=basic*0.5
	pf=basic*0.11
	if grade=='A':
		allow=allowance[0]
	elif grade=='B':
		allow=allowance[1]
	else:
		allow=allowance[2]
	return round(basic+hrd+da+allow-pf+0.01)
