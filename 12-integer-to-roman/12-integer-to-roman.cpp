class Solution {
public:
string intToRoman(int num){
	map<int, char> mp;
	mp[1] = 'I';
	// mp[4] = 'IV';
	mp[5] = 'V';
	mp[10] = 'X';
	mp[50] = 'L';
	mp[100] = 'C';
	mp[500] = 'D';
	mp[1000] = 'M';
	
	string ans = "";
	int p = 1;
	
	while(num > 0){
		int cur = num%10;
		// cur*=p;
		if(cur*p >= 1000){
			for (int i = 0; i < cur; ++i)
			{
				/* code */
				ans.push_back(mp[p]);
			}
		}
		else if(cur*p == 900){
			ans.push_back(mp[1000]);
			ans.push_back(mp[100]);
		}
		else if(cur*p>=500){
			for(int i = 0; i < cur-5; i++){
				ans.push_back(mp[100]);
			}
			ans.push_back(mp[500]);
		}
		else if(cur*p == 400){
			ans.push_back(mp[500]);
			ans.push_back(mp[100]);
		}
		
		else if(cur*p >= 100){
			for(int i = 0; i < cur; i++){
				ans.push_back(mp[100]);
			}
		}
		
		else if(cur*p == 90){
			ans.push_back(mp[100]);
			ans.push_back(mp[10]);
		}
		
		else if(cur*p >= 50){
			for(int i = 0; i < cur-5; i++){
				ans.push_back(mp[10]);
			}
			ans.push_back(mp[50]);
		}
		else if(cur*p == 40){
			ans.push_back(mp[50]);
			ans.push_back(mp[10]);
		}
		
		else if(cur*p >= 10){
			// ans.push_back(mp[10]);
			for(int i = 0; i < cur; i++){
				ans.push_back(mp[10]);
			}
		}
		
		else if(cur*p == 9){
			ans.push_back(mp[10]);
			ans.push_back(mp[1]);
			
		}
		else if(cur*p >= 5){
			for (int i = 0; i < cur-5; ++i)
			{
				/* code */
				ans.push_back(mp[1]);
			}
			ans.push_back(mp[5]);
		}
		
		else if(cur*p == 4){
			ans.push_back(mp[5]);
			ans.push_back(mp[1]);
		}
		else if(cur*p >= 1){
			for(int i = 0; i < cur; i++){
				ans.push_back(mp[1]);
			}
		}
		num = num/10;
		p*=10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
};