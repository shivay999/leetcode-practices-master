/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
**/

//Runtime: 24 ms, faster than 61.49% of C++ online submissions for Find Common Characters.
//Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Find Common Characters.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        
        for(int e : nums){
            if(count.find(e)==count.end()){
                count[e] = 1;
            }else{
                count[e] += 1;
            }
        }
        
        for(map<int, int>::iterator it=count.begin();it!=count.end();it++){
            if(it->second > nums.size()/2){
                return it->first;
            }
        }
        
        return -1;
    }
};

/**
Approach 3: Sorting
Intuition

If the elements are sorted in monotonically increasing (or decreasing) order, 
the majority element can be found at index \lfloor \dfrac{n}{2} \rfloor⌊2n⌋ 
(and \lfloor \dfrac{n}{2} \rfloor + 1⌊2n⌋+1, incidentally, if nn is even).

Algorithm
For this algorithm, we simply do exactly what is described: sort nums, and return the element in question. 
To see why this will always return the majority element (given that the array has one), 
consider the figure below (the top example is for an odd-length array and the bottom is for an even-length array):
**/

/**
Complexity Analysis
Time complexity : O(nlgn)O(nlgn)
Sorting the array costs O(nlgn)O(nlgn) time in Python and Java, so it dominates the overall runtime.
Space complexity : O(1)O(1) or (O(n)O(n))
We sorted nums in place here - if that is not allowed, 
then we must spend linear additional space on a copy of nums and sort the copy instead.
**/

//Runtime: 28 ms, faster than 43.39% of C++ online submissions for Find Common Characters.
//Memory Usage: 11.1 MB, less than 96.02% of C++ online submissions for Find Common Characters.
/**
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
**/

/**
Approach 5: Divide and Conquer
Intuition

If we know the majority element in the left and right halves of an array, 
we can determine which is the global majority element in linear time.

Algorithm

Here, we apply a classical divide & conquer approach that recurses on the left and right halves of an array 
until an answer can be trivially achieved for a length-1 array. 
Note that because actually passing copies of subarrays costs time and space, 
we instead pass lo and hi indices that describe the relevant slice of the overall array. 
In this case, the majority element for a length-1 slice is trivially its only element, 
so the recursion stops there. If the current slice is longer than length-1, 
we must combine the answers for the slice's left and right halves. 
If they agree on the majority element, then the majority element for the overall slice is obviously the same[^1]. 
If they disagree, only one of them can be "right", 
so we need to count the occurrences of the left and right majority elements to determine which subslice's answer is globally correct. 
The overall answer for the array is thus the majority element between indices 0 and nn.
**/

/**
Complexity Analysis

Time complexity : O(nlgn)O(nlgn)

Each recursive call to majority_element_rec performs two recursive calls on subslices of size \frac{n}{2} 
2n and two linear scans of length nn. 
Therefore, the time complexity of the divide & conquer approach can be represented by the following recurrence relation:
T(n) = 2T(\frac{n}{2}) + 2n T(n)=2T(2n)+2n
By the master theorem, the recurrence satisfies case 2, so the complexity can be analyzed as such:
\begin{aligned} T(n) &= \Theta(n^{log_{b}a}\log n) \\ &= \Theta(n^{log_{2}2}\log n) \\ &= \Theta(n \log n) \\ \end{aligned} 
T(n)=Θ(n log b alogn)=Θ(n log 2 2logn)=Θ(nlogn)
Space complexity : O(lgn)O(lgn)

Although the divide & conquer does not explicitly allocate any additional memory, 
it uses a non-constant amount of additional memory in stack frames due to recursion. 
Because the algorithm "cuts" the array in half at each level of recursion, 
it follows that there can only be O(lgn)O(lgn) "cuts" before the base case of 1 is reached. 
It follows from this fact that the resulting recursion tree is balanced, 
and therefore all paths from the root to a leaf are of length O(lgn)O(lgn). 
Because the recursion tree is traversed in a depth-first manner, 
the space complexity is therefore equivalent to the length of the longest path, 
which is, of course, O(lgn)O(lgn).
**/

//TLE
/**
class Solution {
public:
    int countInRange(vector<int>& nums, int num, int lo, int hi){
        int count = 0;
        for(int e : nums){
            if(e==num) count++;
        }
        return count;
    }
    
    int majorityElementRec(vector<int>& nums, int lo, int hi){
        if(lo == hi) return nums[lo];
        
        int mid = (hi+lo)/2;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid+1, hi);
        
        if(left == right) return left;
        
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);
        
        return leftCount > rightCount ? left : right;
    }
    
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size()-1);
    }
};
**/

/**
Approach 6: Boyer-Moore Voting Algorithm
Intuition

If we had some way of counting instances of the majority element as +1+1 and instances of any other element as -1−1, 
summing them would make it obvious that the majority element is indeed the majority element.

Algorithm

Essentially, what Boyer-Moore does is look for a suffix sufsuf of nums where suf[0]suf[0] is the majority element in that suffix. 
To do this, we maintain a count, which is incremented whenever 
we see an instance of our current candidate for majority element and decremented whenever we see anything else.
Whenever count equals 0, we effectively forget about everything in nums up 
to the current index and consider the current number as the candidate for majority element. 
It is not immediately obvious why we can get away with forgetting prefixes of nums - 
consider the following examples (pipes are inserted to separate runs of nonzero count).

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

Here, the 7 at index 0 is selected to be the first candidate for majority element. 
count will eventually reach 0 after index 5 is processed, so the 5 at index 6 will be the next candidate. 
In this case, 7 is the true majority element, so by disregarding this prefix, 
we are ignoring an equal number of majority and minority elements - 
therefore, 7 will still be the majority element in the suffix formed by throwing away the first prefix.

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

Now, the majority element is 5 (we changed the last run of the array from 7s to 5s), but our first candidate is still 7. 
In this case, our candidate is not the true majority element, 
but we still cannot discard more majority elements than minority elements 
(this would imply that count could reach -1 before we reassign candidate, which is obviously false).

Therefore, given that it is impossible (in both cases) to discard more majority elements than minority elements, 
we are safe in discarding the prefix and attempting to recursively solve the majority element problem for the suffix. 
Eventually, a suffix will be found for which count does not hit 0, 
and the majority element of that suffix will necessarily be the same as the majority element of the overall array.
**/

//Runtime: 20 ms, faster than 98.96% of C++ online submissions for Find Common Characters.
//Memory Usage: 11 MB, less than 99.34% of C++ online submissions for Find Common Characters.
/**
Complexity Analysis

Time complexity : O(n)O(n)

Boyer-Moore performs constant work exactly nn times, so the algorithm runs in linear time.

Space complexity : O(1)O(1)

Boyer-Moore allocates only constant additional memory.
**/

/**
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
**/


