class Solution:
    def numberToWords(self, num: int) -> str:
        
        if num == 0 :
            return "Zero"
        
        units = {
            1000000000 : "Billion", 1000000 : "Million", 
		1000 : "Thousand", 100 : "Hundred", 90 : "Ninety", 80 : "Eighty", 
		70 : "Seventy", 60 : "Sixty", 50 : "Fifty", 40 : "Forty", 30 : "Thirty", 
		20 : "Twenty", 19 : "Nineteen", 18 : "Eighteen", 17 : "Seventeen", 
		16 : "Sixteen", 15 : "Fifteen", 14 : "Fourteen", 13 : "Thirteen", 
		12 : "Twelve", 11 : "Eleven", 10 : "Ten", 9 : "Nine", 8 : "Eight", 
		7 : "Seven", 6 : "Six", 5 : "Five", 4 : "Four", 3 : "Three", 2 : "Two", 1 : "One"
                }
        
        nums, string = [1000000000, 1000000, 1000, 1], ""
        
        for i in nums:
            val = num // i
            num = num - val*i
            hundreds, tens, ones, temp = val//100, (val%100)//10, val % 10, ""
            
            if hundreds > 0 :
                temp += units[hundreds] + " Hundred "
            if tens >= 2 :
                temp += units[tens*10] + " "
                
                if ones > 0:
                    temp += units[ones] + " "
            elif tens > 0 or ones > 0:
                temp += units[tens*10 + ones] + " "
            
            if val > 0 and i != 1:
                temp += units[i] + " "
               
            string += temp
            
        return string.strip()
            
        
        
        