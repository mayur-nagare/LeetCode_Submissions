class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1,tag_i=0,tag_j=0;
		while(i<=j) {
			if (s[i]==s[j]) {//Compare the next one at a time 
				i++;
				j--;
			 } else {//Start to modify, there are two modification positions, before and after 
				tag_i = i;
				tag_j = j; 
				i++;
				while (i<=j) {
					if (s[i]==s[j]) {
						i++;
						j--;
					 } else {//Go back and modify another position 
						i = tag_i;
						j = tag_j-1; 
						while(i<=j) {
							if (s[i]==s[j]) {
								i++;
								j--;
							} else return false;
						}
						return true;
					}
				}
				return true; 
			}
		}
		return true; 

    }
};