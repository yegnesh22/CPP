#include <iostream>
#include <jsoncpp/json/json.h>
#include <curl/curl.h>

using namespace std;

#define SCORE_URL "https://s3.eu-west-1.amazonaws.com/hackajob-assets1.p.hackajob/challenges/football_session/football.json"

void TraverseJSONTree(const Json::Value &root, string search, int& goals)
{
	int score1 = 0;
	int score2 = 0;
	if( root.size() > 0 ) {
		for( Json::Value::const_iterator itr = root.begin() ; itr != root.end() ; itr++ ) {
			if (itr.key().isString()) {
				if (itr.key().asString() == "score1") {
					Json::Value s = *itr;
					score1 = s.asInt();
				} if (itr.key().asString() == "score2") {
					Json::Value s = *itr;
					score2 = s.asInt();
				} if (itr.key().asString() == "team1") {
					Json::Value team = *itr;
					if (team["name"] == search)
						goals += score1;
				}
				if (itr.key().asString() == "team2") {
					Json::Value team = *itr;
					if (team["name"] == search)
						goals += score1;
				}
					
			}
			TraverseJSONTree(*itr, search, goals); 
		}
	} 
}


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}


int main(int argc, char* argv[]) 
{
	CURL *curl;
	CURLcode res;
	std::string readBuffer;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl ,CURLOPT_URL, SCORE_URL);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		std::string strJson = readBuffer;
		Json::Reader reader;
		Json::Value obj;
		reader.parse(strJson.c_str(), obj);

		int goals = 0;
		string team;
		if (argc == 2)
			team = string(argv[1]);
		else
			team = string("Liverpool");
		TraverseJSONTree(obj, team, goals);	
		cout << goals << endl;
	}
}

