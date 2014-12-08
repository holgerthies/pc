import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

def int_root(x, n):
	r = int(x**(1.0/float(n)))
	for i in range(r-10,r+11):
		if i>0 and pow(i,n) == x:
			return i
	return None


def is_prime(n):
	if n==2: return True
	if n%2==0: return False
	s = 0
	d = n-1
	while True:
		quotient, remainder = divmod(d, 2)
		if remainder == 1:
			break
		s += 1
		d = quotient
	def try_composite(a):
		if pow(a, d, n) == 1:
			return False
		for i in range(s):
			if pow(a, 2**i * d, n) == n-1:
				return False
		return True # n is definitely composite

	for _ in range(10):
		a = random.randrange(2, n)
       	if try_composite(a):
       		return False
	return True

def factorize(n):
	if n<2:
		return []
	for p in range(2, int(math.sqrt(n))+1):
		if is_prime(p):
			cnt = 0
			if n%p == 0:
				while n % p == 0:
					n /= p
					cnt+=1
				factors = factorize(n)
				factors.append((p,cnt))
				return factors
	return [(n,1)]

def div(n):
	ans = 1
	for p,cnt in factorize(n):
		ans *= (cnt+1)
	return ans

class DivisorsPower:
    def findArgument(self, n):
        i = 2
        if n==1: return 1
        count=0
        while int(n**(1.0/float(i))) > 1:
        	count+=1
        	r = int_root(n,i)
        	if r != None:
        		if div(r) == i:
        			return r
        	i += 1
        return -1

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, hasAnswer, p1):
	sys.stdout.write(str("Test ") + str(testNum) + str(": [") + str(p0))
	print(str("]"))
	obj = DivisorsPower()
	startTime = time.clock()
	answer = obj.findArgument(p0)
	endTime = time.clock()
	res = True
	print(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
	if (hasAnswer):
		print(str("Desired answer:"))
		print(str("\t") + str(p1))
	
	print(str("Your answer:"))
	print(str("\t") + str(answer))
	if (hasAnswer):
		res = answer == p1
	
	if (not res):
		print(str("DOESN'T MATCH!!!!"))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		print(str("Match :-)"))
	else:
		print(str("OK, but is it right?"))
	
	print(str(""))
	return res

all_right = True
tests_disabled = False


# ----- test 0 -----
disabled = False
p0 = 4
p1 = 2
all_right = (disabled or KawigiEdit_RunTest(0, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = 10
p1 = -1
all_right = (disabled or KawigiEdit_RunTest(1, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = 64
p1 = 4
all_right = (disabled or KawigiEdit_RunTest(2, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = 10000
p1 = 10
all_right = (disabled or KawigiEdit_RunTest(3, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = 2498388559757689
p1 = 49983883
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------
# ----- test 4 -----
disabled = False
p0 = pow(10,18)
p1 = 100
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = 926680334444501641
p1 = 962642371
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled

if (all_right):
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# PROBLEM STATEMENT
# Halina is a young mathematician.
# Recently she has been studying an interesting function h that operates on positive integers.
# 
# Let d(n) be the number of distinct positive divisors of n.
# The function h is then defined as follows: for each n we have h(n) = n^d(n).
# In words, h(n) is defined as n to the power of d(n).
# 
# For example, d(6)=4 because 6 is divisible by 1, 2, 3, and 6.
# Then, h(6) = 6^4 = 1296.
# 
# Halina already knows how to compute her function h.
# Now she would like to compute the inverse function.
# Help her!
# 
# You are given a long integer n.
# Return the smallest x such that h(x) = n.
# If there is no such x, return -1 instead.
# 
# DEFINITION
# Class:DivisorsPower
# Method:findArgument
# Parameters:long integer
# Returns:long integer
# Method signature:def findArgument(self, n):
# 
# 
# CONSTRAINTS
# -n will be between 2 and 10^18, inclusive.
# 
# 
# EXAMPLES
# 
# 0)
# 4
# 
# Returns: 2
# 
# d(2) = 2, h(2) = 4
# 
# 1)
# 10
# 
# Returns: -1
# 
# There is no x satisfying h(x) = 10.
# 
# 2)
# 64
# 
# Returns: 4
# 
# d(4) = 3, h(4) = 64
# 
# 3)
# 10000
# 
# Returns: 10
# 
# d(10) = 4, h(10) = 10000
# 
# 4)
# 2498388559757689
# 
# Returns: 49983883
# 
# 
# 
# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!
