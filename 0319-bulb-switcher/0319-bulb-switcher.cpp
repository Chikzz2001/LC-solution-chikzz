class Solution {
public:
    int bulbSwitch(int n) {
        //The ith bulb gets toggled when it is the jth turn(Here j is a factor of i)
        //Now we can divide numbers into two category one with even no of factors and one with odd number of factors
        //We know that for every factor j<=sqrt(i) we have i/j>=sqrt(i) so there are factors in pairs {j,i/j} 
        //where j!=i/j(for all numbers but squares)-->these numbers have even factors
        //For perfect squares we have a pair {sqrt(i),sqrt(i)} so for square numbers we have odd factors
        
        //for even factors ith bulb will be switched off.
        //for odd factors ith bulb will be turned on.
        //We know total number of perfect squares between 1 and n is sqrt(n)-->hence the ans is sqrt(n)
        return sqrt(n);
    }
};