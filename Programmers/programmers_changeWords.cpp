#include <string>
#include <vector>

using namespace std;
bool visited[50];
int min = 100;

void dfs(string begin, string target, vector<string> words, int count) {
	char c[begin.length];
	c = begin;
	if (begin == target) {
		if (count < min) min = count;
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		char temp[begin.length];
		temp = words[i];
		int tempCount = 0;
		for (int j = 0; j < temp.length; j++) {
			if (temp[j] != c[j]) {
				tempCount++;
			}
		}
		if (tempCount <= 1 && !visited[i]) {
			visited[i] = true;
			dfs(temp, target, words, count + 1);
			visited[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	N = begin.length;
	dfs(begin, target, words, 0);
	answer = min;
	return answer;
}