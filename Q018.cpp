#include<iostream>
#include<string>
#include<hash_map>
using namespace std;

void parse(string s, hash_map<string, int> & map){
	int i, wordN = 0;
	char word[64];
	for(i=0;i<s.length();i++){
		// printf("%c",s[i]);
		if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '"'){
			if(wordN!=0){
				word[wordN] = '\0';
				if(map.find(word)!=map.end())
					map[word] += 1;
				else
					map[word] = 1;
			}
			wordN = 0;
		}else{
			word[wordN++] = s[i];
		}
	}
}

void print(hash_map<string, int> map){
	for(hash_map<string, int>::iterator it = map.begin();it!=map.end(); it++){
		cout << it->first << "\t" << it->second <<endl;
	}

}

int istrendmicro(hash_map<string, int> map){
	char * keep[] = {"Trend","Micro","Steve", "Jenny","1988","1984",
				"United","Asia"};
	int sum = 0;
	for(int i=0;i<8; i++){
		sum += map[ keep[i] ];
	}
	//cout<<sum<<endl;
	return sum>5;
}

int main(){
	string s;
	
	while(!cin.eof()){
		hash_map<string,int> map;
		getline(cin, s);
		parse(s, map);
		//print(map);
		printf("%d\n",istrendmicro(map));
		
	}

}
