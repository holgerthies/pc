import math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from collections import defaultdict

np = dict()
def num_palin(letter_list):
	if letter_list in np:
		return np[letter_list]
	ans = 0
	if len(letter_list) <= 1:
		np[letter_list] = 1
		return 1
	if letter_list.count(1) > 1:
		np[letter_list] = 0
		return 0
	for i,c in enumerate(letter_list):
		if c >= 2:
			new_letter_list = list(letter_list[:])
			new_letter_list[i] -= 2
			if new_letter_list[i] == 0:
				new_letter_list = new_letter_list[:i]+new_letter_list[i+1:]
			new_letter_list = tuple(sorted(new_letter_list))
			ans += num_palin(new_letter_list)
	np[letter_list] = ans
	return ans

fac = dict()
fac[0] = 1
def factorial(n):
	if n in fac:
		return fac[n]
	else:
		fac[n] = factorial(n-1)*n
	return fac[n]

def num_anagrams(letter_list):
	div = 1
	for c in letter_list:
		div *= factorial(c)
	return factorial(sum(letter_list))/div

def N(word):
	count = defaultdict(int)
	for w in word:
		count[w] += 1
	nums = []
	for key in count:
		nums.append(count[key])
	nums = tuple(sorted(nums))
	return num_palin(nums), num_anagrams(nums)




class PalindromePermutations:
    def palindromeProbability(self, word):
        np, na = N(word)
        print np, na
        return float(np)/float(na)

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, hasAnswer, p1):
	sys.stdout.write(str("Test ") + str(testNum) + str(": [") + str("\"") + str(p0) + str("\""))
	print(str("]"))
	obj = PalindromePermutations()
	startTime = time.clock()
	answer = obj.palindromeProbability(p0)
	endTime = time.clock()
	res = True
	print(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
	if (hasAnswer):
		print(str("Desired answer:"))
		print(str("\t") + str(p1))
	
	print(str("Your answer:"))
	print(str("\t") + str(answer))
	if (hasAnswer):
		res = answer == answer and abs(p1 - answer) <= 1e-9 * max(1.0, abs(p1))
	
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
p0 = "haha"
p1 = 0.3333333333333333
all_right = (disabled or KawigiEdit_RunTest(0, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = "xxxxy"
p1 = 0.2
all_right = (disabled or KawigiEdit_RunTest(1, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = "xxxx"
p1 = 1.0
all_right = (disabled or KawigiEdit_RunTest(2, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = "abcde"
p1 = 0.0
all_right = (disabled or KawigiEdit_RunTest(3, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"
p1 = 0.025641025641025637
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# PROBLEM STATEMENT
# A palindrome is a word that reads the same forwards and backwards. For example, "a", "abba", and "zzz" are palindromes, while "ab" and "xxxyx" are not.
# 
# The anagram of a string S is any string we can obtain from S by rearranging its letters. For example, the string "haha" has exactly six anagrams: "aahh", "ahah", "ahha", "haah", "haha", and "hhaa".
# 
# We are given a string word. We will choose one of its anagrams uniformly at random. Return the probability that the chosen anagram will be a palindrome.
# 
# DEFINITION
# Class:PalindromePermutations
# Method:palindromeProbability
# Parameters:string
# Returns:float
# Method signature:def palindromeProbability(self, word):
# 
# 
# NOTES
# -The returned value must have an absolute or a relative error of less than 1e-9.
# 
# 
# CONSTRAINTS
# -word will contain between 1 and 50 characters, inclusive.
# -Each character of word will be a lowercase English letter ('a'-'z').
# 
# 
# EXAMPLES
# 
# 0)
# "haha"
# 
# Returns: 0.3333333333333333
# 
# Each of the six anagrams of "haha" will be selected with probability 1/6.
# Two of them are palindromes: "ahha" and "haah".
# Hence, the probability of selecting a palindrome is 2/6.
# 
# 1)
# "xxxxy"
# 
# Returns: 0.2
# 
# 
# 
# 2)
# "xxxx"
# 
# Returns: 1.0
# 
# This word only has one anagram: "xxxx". That is a palindrome.
# 
# 3)
# "abcde"
# 
# Returns: 0.0
# 
# Regardless of how we rearrange the letters of "abcde", we will never get a palindrome.
# 
# 4)
# "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"
# 
# Returns: 0.025641025641025637
# 
# 
# 
# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!
