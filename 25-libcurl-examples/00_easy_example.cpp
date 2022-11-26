
/* 
 * Check video https://www.youtube.com/watch?v=5oOrRLa2XCE
 */

#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using namespace std;

size_t get_response(void *content, size_t isize, size_t nmemb, void *userp) {
  ((string *) userp)->append((char *) content, isize * nmemb);
  return isize * nmemb;
}


int main(int argc, char const *argv[]) {
  char url[] = "https://reqres.in/api/users/2";
  string readBuffer;

  CURL *curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_response);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    CURLcode res = curl_easy_perform(curl);
    
    if(res == CURLE_OK) {
      cout << "OK" << endl;
    }
    curl_easy_cleanup(curl);
  }

  // parse user
  using namespace nlohmann;
  json person = json::parse(readBuffer);
  cout << "first name: " << person["data"]["first_name"] << endl;
  
  return 0;
}