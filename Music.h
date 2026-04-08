#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Music {
private:
	string title;
	string artist;
	string album;
	int year;
public:
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}
	//Getters
	string getTitle() { return title; }
	string getArtist() { return artist; }
	string getAlbum() { return album; }
	int getYear() { return year; }
};

//MusicStreamingService Class
class MusicStreamingService {
private:
	string serviceName;
	vector<Music> musicList;
public:
	MusicStreamingService(string serviceName) {
		this->serviceName = serviceName;
	}
	void addMusic(string title, string artist, string album, int year) {
		Music newMusic(title, artist, album, year);
		musicList.push_back(newMusic);
		cout << title << "by" << artist << "added to" << serviceName << endl;
	}
	Music* searchbyTitle(string title) {
		for (int i = 0; i < musicList.size(); i++) {
			if (musicList[i].getTitle() == title)
				return &musicList[i];
		}
		return NULL;
	}
	//Artist로 검색하기
	vector<Music*> searchByArtist(string Artist) {
		vector<Music*> result;
		//musicList에 있는 artist와 입력 artist가 같으면 result에 push_back
		for (int i = 0; i < musicList.size(); i++) {
			if (musicList[i].getArtist() == Artist) {
				result.push_back(&musicList[i]);
			}
		}
		return result;
	}
};