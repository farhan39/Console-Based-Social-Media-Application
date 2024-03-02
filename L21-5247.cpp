//Muhammad Farhan Bukhari------------BCS-2F----------21L-5247
	
#include<iostream>
#include<fstream>
using namespace std;

class object;		// this class inherits only ID of user, page, post and comment class.
class Facebook;
class users;
class pages;
class Post;
class Activity;
class Helper;
class Comment;
class Date;
class Memory;

template<class any>
void Deallocate(any** doublePTR)
{
	for (int i = 0 ; doublePTR[i] != nullptr ; i++)
		delete[] doublePTR[i];
	delete[] doublePTR;
}

class Helper
{
public:

	static int stringLength(char* temp)
	{
		int i = 0;
		while (temp[i] != '\0')
			i++;

		return i;
	}

	static char* stringCopy(char* temp, int size)
	{
		char* temp1 = new char [size + 1];
		for (int i = 0 ; i < size ; i++)
		{
			temp1[i] = temp[i];
		}

		temp1 [size] = '\0';
		return temp1;

	}

	static char* GetStringFromBuffer(char* temp)
	{
		int size = stringLength(temp);
		char* temp1 = stringCopy(temp, size);
		return temp1;
	}

	static char* stringConcatenate(char* string1, char* string2)
	{
		int str1Length = stringLength(string1);
		int str2Length = stringLength(string2);

		char tempBuffer[80] = { '\0' };
		for (int i = 0 ; i < str1Length ; i++)
			tempBuffer[i] = string1[i];

		int finalLength = str1Length + str2Length;		// found final length required to store both string1 and string2 

		for (int j = 0 , i = str1Length ; j < str2Length && i < finalLength ; j++, i++)
			tempBuffer[i] = string2[j];

		char* returnString = new char [finalLength+1];

		int i = 0;
		while (1)
		{
			returnString[i] = tempBuffer[i];
			if (tempBuffer[i] == '\0')
			{
				string1[i] = '\0';		// storing null character too.
				break;
			}
			i++;
		}
		return returnString;

	}

	static int compareString(char *string1,char *string2)
	{
		int str1Length = stringLength(string1);
		int str2Length = stringLength(string2);

		for (int i = 0 ; i < str1Length && i < str2Length ; i++)
			{
				if (( string1[i]-32 == string2[i] ) || ( string1[i]+32 == string2[i] ))	//e.g if a == A or A == a 
					return 1;

				if (( string2[i]-32 == string1[i] ) || ( string2[i]+32 == string1[i] ))
					return -1;

				if(string1[i]>string2[i])
					return 1;

				if(string1[i]<string2[i])
					return -1;
			}

			return 0;
	}

	static char* intToStr(int num)
	{
		int rem = 10;
		int i = 0;
		int div = num;

		while (div != 0)
		{
			rem = div % 10;
			div = div / 10;
			i++;
		}

		char* temp = new char[i+1];
		int j =i;

		while (num != 0)
		{
			rem = num % 10;
			temp[j] = (char)rem +48;
			num= num/10;
			j--;
		}

		temp[i+1] = '\0';
		return temp;
	}

	static int returnIndexOfobjectId(char* temp)
	{
		int index = 0, len = Helper::stringLength(temp); 
	
		if (len == 2)
		index = (int)temp[1] - 49;
    
		else if(len == 3)
		index = ((int)temp[1] - 48) * 10 + ((int) temp[2] - 49);
    
		return index;
	}
};

class Date{

	private: 
		int Day,Month,Year;
	public: 
		static Date currentDate;

		Date(int date = 0,int month = 0,int year = 0)
		{
			Day = date;
			Month = month;
			Year = year;
		}
		void Print()
		{
			cout << "\t(" << Day << "/" << Month << "/" << Year << ")" << endl;
		}
		void setDay(int temp)
		{	
			Day = temp;	
		}
		int getDay()
		{
			return Day;
		}
		int getMonth()
		{
			return Month;
		}
		int getYear()
		{
			return Year;
		}
		void setMonth(int temp)
		{
			Month = temp;
		}
		void setYear(int temp)
		{
			Year = temp;
		}
		static void setCurrentDate(int day, int month, int year)
		{
			currentDate.Day = day;
			currentDate.Month = month;
			currentDate.Year = year;
		}
		static int getCurrentDay()
		{
			return currentDate.Day;
		}

		void setDate(int dt, int mo, int yr)
		{
			Day = dt;
			Month = mo;
			Year = yr;
		}
};

Date Date::currentDate;

class object
{
protected:
	char* id;
public: 
	object(char* id1 = NULL)
	{
		if (id1 != NULL)
		id = Helper::GetStringFromBuffer(id1);
		else id = NULL;
	}
	virtual ~object()
	{
		if (id != NULL)
		delete[] id;
		id = NULL;
	}
	void setID(char* str)
	{
		id = Helper::stringCopy(str, Helper::stringLength(str));
	}
	char* getID()
	{
		if (id != NULL)
		return id;
		else return nullptr;
	}
	virtual void printName()
	{
		for (int i = 0 ; i < Helper::stringLength(id) ; i++)
		cout << id ;
	}
};

class Activity
{
	int type;
	char* value;
public:
	Activity(int typ = 0, char* value1 = NULL)
	{
		type = typ;

		if (value1 != NULL)
		value = Helper::GetStringFromBuffer(value1);
		else value = NULL;
	}

	~Activity()
	{
		if (value != NULL)
		delete[] value;
	}

	void setType(int temp)
	{
		type = temp;
	}

	void setValue(char* temp)
	{
		value = Helper::GetStringFromBuffer(temp);
	}

	void setActivity(int type, char* temp)
	{
		setType(type);
		setValue(temp);
	}
	int getType()
	{
		return type;
	}
	char* getValue()
	{
		return value;
	}

	void printActivity()
	{
		if (type == 1)
		{
			cout << " is feeling ";
			for (int i = 0 ; i < Helper::stringLength(value); i++)
				cout << value[i];
		}

		if (type == 2)
		{
			cout << " is thinking about ";
			for (int i = 0 ; i < Helper::stringLength(value); i++)
				cout << value[i];
		}

		if (type == 3)
		{
			cout << " is making";
			for (int i = 0 ; i < Helper::stringLength(value); i++)
				cout << value[i];
		}

		if (type == 4)
		{
			cout << " celebrating ";
			for (int i = 0 ; i < Helper::stringLength(value); i++)
				cout << value[i];
		}


	}
};

class Comment : public object
{
	char* text;
	object* commentator;

public:
	static int totalComments;
	Comment()
	{
		text = nullptr;
		commentator = nullptr;
	}
	Comment(char* txt, object* _commentator)
	{
		text = Helper::GetStringFromBuffer(txt);
		commentator = _commentator;
	}
	~Comment()
	{
		if (text)
			delete[] text;
		if (commentator)
			delete[] commentator;
	}
	void printListView()
	{
		cout << "	";
		commentator->printName();
		cout << " wrote : ";
		for (int i = 0; i < Helper::stringLength(text); i++)
			cout << text[i];
		cout <<endl;
	}
	void setText(char* txt)
	{
		text = Helper::GetStringFromBuffer(txt);
	}
	void setCommentator(object* _commentator)
	{
		commentator = _commentator;
	}
	char *getText() 
	{ 
		return text; 
	}
	object *getCommentator() 
	{
		return commentator;
	}

};

int Comment:: totalComments = 0;

class Post : public object
{
	Activity* anyActivity;
	char* description;
	Date postedDate;
	object* shared;
	Comment** Comments;
	object** liked;
	int commentCount;
	int likeCount;
	int shareCount;
	
public:

	static int totalPosts;
	Post()
	{
		description = nullptr;
		shared = nullptr;
		Comments = nullptr;
		liked = nullptr;
		likeCount = 0;
		commentCount = 0;
		shareCount = 0;
		anyActivity = NULL;
	}

	~Post()
	{
		if (description)
			delete[] description;
		
		shared = NULL;

		if(Comments)
			delete[] Comments;

		if (liked)
			delete[] liked;	

		if (anyActivity)
			delete[] anyActivity;
	}

	void ReadPostsFromFile(ifstream &);

	void addNewComment(Comment* _comment)
	{
		if (Comments == NULL)
		{
			Comments = new Comment* [10];
			for (int i = 0; i < 10; i++)
				Comments[i] = nullptr;
		}

		if (commentCount < 10)
		{
			Comments[commentCount] = new Comment;
			Comments[commentCount + 1] = nullptr;
			char tempID[4] = "c";
			
			char* temp = Helper::intToStr(commentCount);
			char* concatenatedStr = Helper::stringConcatenate(tempID, temp);

			Comments[commentCount]->setCommentator(_comment->getCommentator());
			Comments[commentCount]->setText(_comment->getText());
			Comments[commentCount]->setID(concatenatedStr);

			commentCount++;
		}
		else cout << "No more comments allowed !\n";
		
	}

	void setComment(Comment** temp)
	{
		if (temp != NULL)
		{
			if (Comments == NULL)
			{
				Comments = new Comment* [10];
				for (int i = 0 ; i < 10 ; i++)
					Comments[i] = NULL;
			
				for (int i = 0 ; i < commentCount; i++)
				{
					Comments[i] = new Comment;
					Comments[i]->setCommentator(temp[i]->getCommentator());
					Comments[i]->setText(temp[i]->getText());
				}
			}
		}

		else Comments = NULL;
	}

	void setShared(object* temp)
	{
		shared = temp;
	}

	void setLiked(object* temp)
	{
		if (liked == nullptr)
			liked = new object* [10];
		if (likeCount < 10)
		{
			liked[likeCount] = temp;
			liked[likeCount+1] = temp;
		}

		likeCount++;
	}

	void printListView()
	{
		cout << "/";
		for (int i = 0; i < Helper::stringLength(description) ; i++)
			cout << description[i];
		cout << "/";
	}

	void printDetailedView()
	{
		cout << endl;

		
		if (shared != NULL )
		{
			shared->printName();
		}

		if (anyActivity != NULL)
		{
			anyActivity->printActivity();
		}
		else cout << " shared ";

		cout <<" \"";
		
		for (int i = 0; i < Helper::stringLength(description); i++)
			cout << description[i];
		
		cout << "\" ";
		postedDate.Print();
		

		if (Comments != NULL)
		{
			for (int i = 0 ; i < commentCount ; i++)
				Comments[i]->printListView();
		}

		cout << endl;
	}

	void printMemory()
	{
		if (shared != NULL )
		{
			shared->printName();
		}
		cout << "shared a memory\n";

	}

	void addComment(Comment *_comment)
	{
		if (Comments == nullptr)
			Comments = new Comment* [10];
		if (commentCount < 10)
			Comments[commentCount] = _comment;
		commentCount++;
	}

	void setDescription(char *des)
	{
		description = Helper::stringCopy(des, Helper::stringLength(des));
	}

	char* getDescription()
	{
		return description;
	}

	void setDate(Date date)
	{
		postedDate.setDate(date.getDay(), date.getMonth(), date.getYear());
	}

	Date getDate()
	{
		return postedDate;
	}

	int getPostedDay()
	{
		return postedDate.getDay();
	}

	Comment** getComment()
	{
		return Comments;
	}

	int getCommentCount()
	{
		return commentCount;
	}

	void setCommentCount(int hello)
	{
		commentCount = hello;
	}

	object* getShared()
	{
		if (shared != NULL)
		return shared;
		else return nullptr;
	}

	int getShareCount()
	{
		return shareCount;
	}

	void showLiked()
	{
		cout << "Post liked by :\n\t";

		for (int i = 0 ; i < likeCount; i++)
			liked[i]->printName();
	}

	int getLikeCount()
	{
		return likeCount;
	}

	void setLikeCount(int hello)
	{
		likeCount = hello;
	}

	void setLikedUser(object** _liked)
	{
		if(liked == NULL)
		{
			liked = new object*[10];
			for (int i = 0 ; i < 10 ;i++)
				liked[i] = 0;

			for (int i = 0 ; i < likeCount ;i++)
				liked[i] = _liked[i];
		}
	}

	object** getLiked()
	{
		return liked;
	}

	void setActivity(Activity* ptr)
	{
		if (anyActivity == NULL)
			anyActivity = new Activity;
		if (ptr != nullptr)
		{
			anyActivity->setType(ptr->getType());
			anyActivity->setValue(ptr->getValue());
		}
		else anyActivity = nullptr;
	}

	Activity* getActivity()
	{
		if (anyActivity)
		return anyActivity;
		else return nullptr;
	}
};

int Post::totalPosts = 0;

class Memory : public Post
{
	Post* anyMemory;
public:
	Memory(Post* temp = nullptr)
	{
		anyMemory = temp;
	}
	~Memory()
	{
		/*if (anyMemory)
		delete[] anyMemory;*/
	}
	void setMemory(Post* ptr)
	{
		if (anyMemory == nullptr)
			anyMemory = new Post;
		anyMemory = ptr;
	}
};

void Post:: ReadPostsFromFile(ifstream& fin)
{
	int tempVar = 0;
	char tempBuffer[100];

	fin >> tempVar;
	
	if (tempVar != 1)
	{
		fin >> tempBuffer;
		id = Helper::GetStringFromBuffer(tempBuffer);

		fin >> tempVar;
		postedDate.setDay(tempVar);

		fin >> tempVar;
		postedDate.setMonth(tempVar);

		fin >> tempVar;
		postedDate.setYear(tempVar);

		fin.ignore();
		fin.getline(tempBuffer,100);
		description = Helper::GetStringFromBuffer(tempBuffer);

		anyActivity = new Activity;
		fin >> tempVar;
		anyActivity->setType(tempVar);

		fin.getline(tempBuffer,100);
		anyActivity->setValue(tempBuffer);
	}

	else 
	{
		fin >> tempBuffer;
		id = Helper::GetStringFromBuffer(tempBuffer);

		fin >> tempVar;
		postedDate.setDay(tempVar);

		fin >> tempVar;
		postedDate.setMonth(tempVar);

		fin >> tempVar;
		postedDate.setYear(tempVar);

		fin.ignore();
		fin.getline(tempBuffer,100);
		description = Helper::GetStringFromBuffer(tempBuffer);
	}

}

class pages : public object
{
	char* title;
	Post** timeline;
	int totalPosts;

public:

	static int totalPages;
	pages(char*, char*);

	void ReadPageFromFile(ifstream&);

	void addPost(Post*& rhs);

	char*& getPageId();

	void print();

	void printTimeline()
	{
		for (int i = 0; i < totalPosts ; i++)
			timeline[i]->printDetailedView();
	}

	void printPosts()
	{
		for (int i = 0; i < totalPosts; i++)
		{
			int postedDate = timeline[i]->getPostedDay();
			int currentDate = Date::getCurrentDay();

			if (currentDate == postedDate || currentDate - postedDate == 1)
				timeline[i]->printDetailedView();
		}
	}

	void printName();

	~pages();
};

int pages:: totalPages = 0;

pages::pages(char* id = NULL, char* title1 = NULL) : object(id)
{
	if (title1 != NULL)
	title = Helper::GetStringFromBuffer(title1);
	else title = NULL;
	timeline = nullptr;
	totalPosts = 0;
}

pages::~pages()
{
	if(title != NULL)
		delete[] title;

	if (timeline)
		/*for (int i = 0 ; i < pages::totalPosts ; i++)
			delete timeline[i];*/
		delete[] timeline;
}

char*& pages::getPageId()
{
	return id;
}

void pages:: print()
{
	int idLen = Helper::stringLength(id);
	int titleLen = Helper::stringLength(title);

	for (int i = 0 ; i < idLen ; i++)
		cout << id[i];
	
	cout << " ";
	for (int i = 0 ; i < titleLen ; i++)
		cout << title[i];

}

void pages::printName()
{
	for (int i = 0 ; i < Helper::stringLength(title) ; i++)
		cout << title[i];
}

void pages:: addPost(Post*& rhs)
{
	if (timeline == NULL)
	{
		timeline = new Post* [10];
		for (int i = 0; i <10; i++)
		{
			timeline[i] = NULL;
		}	
	}
	if (totalPosts < 10)
	{
		for (int i = 0; i<10; i++)
		{
			if (timeline[i] == NULL)
			{
				timeline[i] = new Post;
				timeline[i]->setID(rhs->getID());
				timeline[i]->setDescription(rhs->getDescription());
				timeline[i]->setDate(rhs->getDate());
				timeline[i]->setShared(rhs->getShared());
				timeline[i]->setCommentCount(rhs->getCommentCount());
				timeline[i]->setComment(rhs->getComment());
				totalPosts++;
				break;
			}
		}
	}
	else
	{
	cout << "MAXIMUM NO. OF POSTS HAVE REACHED\n";
	}

}

void pages:: ReadPageFromFile(ifstream& fin)
{
	char tempBuffer[30];

	if (id == NULL)
	{
		fin>>tempBuffer;
		id = Helper::GetStringFromBuffer(tempBuffer);
	}

	if (title == NULL)
	{
		title = new char[50];
		fin.getline(title,50);
	}
}

class users : public object
{
	char* Fname;
	char* Lname;
	users** FriendList;
    pages** likedPages;
	int likeCount;
    int friendCount;
	int postCount;
	int memoryCount;
	Post** timeline;
	Memory* myMemories;

public:

	static int totalUsers;
	users(char*, char*, char*);

	void ReadUsersFromFile(ifstream&, char**&);

	void likePage(pages*);

	void addFriend(users*);

	char*& getUserId();

	void printName();

	void displayFriendList();

	void displayLikedPages();

	void printPosts()
	{
		for (int i = 0; i < postCount; i++)
		{
			int currentDate = Date::getCurrentDay();
			int postedDate = timeline[i]->getPostedDay();

			if (currentDate == postedDate || currentDate - postedDate == 1)
				timeline[i]->printDetailedView();
		}
	}

	void printHomepage()
	{
		printName();
		cout << " home Page :\n";

		for (int i = 0 ; i < friendCount; i++)
			FriendList[i]->printPosts();

		for (int i = 0; i < likeCount; i++)
			likedPages[i]->printPosts();
	}

	void printTimeline()
	{
		for (int i = 0; i < postCount ; i++)
			timeline[i]->printDetailedView();
	}

	void setMemory(Date myDate)
	{
		for (int i = 0 ; i < postCount ; i++)
		{
			if (myDate.getYear() > timeline[i]->getDate().getYear() && myDate.getDay() == timeline[i]->getDate().getDay())
			{
				myMemories = new Memory;
				myMemories[i].setMemory(timeline[i]);
				memoryCount++;
				break;
			}
		}
	}

	void shareMemory(char* id, char* text, object* sharedBy)
	{
		myMemories[memoryCount].setID(id);
			
		myMemories[memoryCount] = new Memory;
		myMemories[memoryCount].setDescription(text);
		myMemories[memoryCount].setDate(Date::currentDate);
		myMemories[memoryCount].setShared(sharedBy);

		myMemories[memoryCount].printMemory();

		myMemories[memoryCount].getDate().Print();
			
		for (int i = 0; i < Helper::stringLength(myMemories[memoryCount].getDescription()); i++)
			cout << myMemories[memoryCount].getDescription()[i];
	}

	void addPost(Post* &rhs);

	~users();
};

int users:: totalUsers = 0;

users::users(char* id = NULL, char* Fname1 = NULL, char* Lname1 = NULL) : object(id)
{
	if (Fname1 != NULL)
	Fname = Helper::GetStringFromBuffer(Fname1);
	else Fname = NULL;

	if (Lname1 != NULL)
	Lname = Helper::GetStringFromBuffer(Lname1);
	else Lname = NULL;

	FriendList = NULL;
	likedPages = NULL;
	timeline = NULL;
	myMemories = NULL;
	likeCount = 0;
    friendCount = 0;
	postCount = 0;
	memoryCount = 0;
}

char*& users:: getUserId()
{  
    return id;
}

users :: ~users()
{

	if (Fname != NULL)
	delete[] Fname;

	if (Lname != NULL)
	delete[] Lname;

	if (FriendList != NULL)
		delete[] FriendList;
	
	if (likedPages != NULL)
		delete[] likedPages;

	if (timeline != NULL)
		delete[] timeline;

	/*if (myMemories != NULL)
		delete[] myMemories;*/
}

void users:: ReadUsersFromFile(ifstream& fin, char**& tempFriends)
{
	char tempBuffer[30];

	fin >> tempBuffer;
	id = Helper::GetStringFromBuffer(tempBuffer);

	fin>>tempBuffer;
	Fname = Helper::GetStringFromBuffer(tempBuffer);
	
	fin>>tempBuffer;
	Lname = Helper::GetStringFromBuffer(tempBuffer);

	int x = 0;
	fin >> tempBuffer;

	if (tempBuffer[0] == '-')
	{
		FriendList = NULL;
		tempFriends[x] = NULL;
	}
	else
	{
		while (Helper::compareString(tempBuffer,"-1"))    
		{
			tempFriends[x] = Helper::GetStringFromBuffer(tempBuffer);
			tempFriends[x+1] = NULL;

			fin >> tempBuffer;
			x++;
		}
	}
}

void users::addPost(Post*& rhs)
{

	if (timeline == NULL)
	{
		timeline = new Post *[10];
		for (int i = 0; i <10; i++)
		{
			timeline[i] = 0;
		}
	}

	if(postCount < 10)
	{
		for (int i = 0; i < 10 ; i++)
		{
			if (timeline[i] == NULL)
			{
				timeline[i] = new Post;
				char ID[10] = "post";
				
				char *temp = Helper::intToStr(postCount);
				char* concatenatedID = Helper::stringConcatenate(ID, temp);

				timeline[i]->setID(concatenatedID);
				timeline[i]->setDescription(rhs->getDescription());
				timeline[i]->setActivity(rhs->getActivity());
				timeline[i]->setShared(rhs->getShared());
				timeline[i]->setDate(rhs->getDate());
				timeline[i]->setCommentCount(rhs->getCommentCount());
				timeline[i]->setComment(rhs->getComment());
				postCount++;
				break;
			}
		}
	}
	else
	{
		cout << "No more posts allowed !\n";
	}
}

void users:: likePage(pages* temp)
{
	if (likedPages == NULL)
		likedPages = new pages* [10]; 

	likedPages[likeCount] = temp;
	likedPages[likeCount+1] = NULL;
	likeCount++;
}

void users:: addFriend(users* temp)
{
    if (FriendList == NULL)
		FriendList = new users* [20]; 


	FriendList[friendCount] = temp;
	FriendList[friendCount+1] = '\0';
	friendCount++;
}

void users:: displayFriendList()
{
	cout << "Friend List :\n";

	if (FriendList != NULL)
	for (int i = 0 ; FriendList[i] != '\0' ; i++)
	{		
		cout << FriendList[i]->id << " ";

		FriendList[i]->printName();
		cout << endl;
	}
	else cout << "No Friends of this user !\n";
}

void users:: displayLikedPages()
{
	cout << "Liked Pages :\n";

	if (likedPages != NULL)
	for (int i = 0 ; likedPages[i] != '\0' ; i++)
	{		
		likedPages[i]->print();
		cout << endl;
	}
	else cout << "No Liked Pages !\n";
}

void users:: printName()
{
	int FnameLen = Helper::stringLength(Fname);
	int LnameLen = Helper::stringLength(Lname);

	cout << "\t";
	for (int i = 0 ; i < FnameLen ; i++)
		cout << Fname[i];
	
	cout << " ";
	for (int i = 0 ; i < LnameLen ; i++)
		cout << Lname[i];
}

class facebook
{
	pages** Pages;
	users** Users;
	Comment** comments;
	Post** posts;

	users* currentUser;

public:

	facebook();
	void Run();
	void LoadData(char*, char*, char*, char*);
	void LoadPages(char*);
	void LoadUsers(char*);
	void LoadPosts(char*);
	void LoadComments(char*);
	void setCurrentUser(char*);

	pages* searchPageById(char[]);
    users* searchUserById(char[]);
	Post* searchPostById(char[]);
	object* searchObjectById(char[]);
	
	~facebook();
};

facebook:: facebook()
{
	Pages = NULL;
	Users = NULL;
	posts = NULL;
	comments = NULL;
	currentUser = NULL;
}

facebook:: ~facebook()
{

	if (Pages != nullptr)
		for (int i = 0 ; i < pages::totalPages ; i++)
		delete Pages[i];
	delete[] Pages;

	if (posts != nullptr)
	/*	for (int i = 0 ; i < Post::totalPosts ; i++)
			if (posts[i] != nullptr)
				delete posts[i];*/
	delete[] posts;

	if (comments != nullptr)
		for (int i = 0 ; i < Comment::totalComments ; i++)
			if (posts[i] != nullptr)
				delete comments[i];
		delete[] comments;

	currentUser = NULL;

	/*if (Users != nullptr)
		delete[] Users;*/

}

users* facebook :: searchUserById(char temp[])
{
    int tempLen = Helper::stringLength(temp);
	int i = 0;

	if (Users != NULL)
	for (int i = 0 ; Users[i] != NULL  ; i++)
	{
		int UIDlen = Helper::stringLength(Users[i]->getID());

		if (UIDlen == tempLen)
		{
			int var1 = Helper::compareString(Users[i]->getID(), temp);
		
			if (var1 == 0)
				return Users[i];
		}
	}

	return NULL;
}

pages* facebook :: searchPageById(char temp[])
{
	int tempLen = Helper::stringLength(temp);

	if (Pages != NULL)
	for (int i = 0 ; Pages[i] != NULL ; i++)
	{
		int PIDlen = Helper::stringLength(Pages[i]->getID());
		if (tempLen == PIDlen)
		{
			int var1 = Helper::compareString(Pages[i]->getID(), temp);
		
			if (var1 == 0)
			return Pages[i];
		}
	}

	return NULL;
}

object* facebook :: searchObjectById(char temp[])
{
	if (temp[0] != '-')
		{
			char* randomID = Helper::stringCopy(temp, Helper::stringLength(temp));

			if (randomID[0] == 'u')
				return (searchUserById(randomID));
			else
				return (searchPageById(randomID));
		}
	else return nullptr;
}

Post* facebook:: searchPostById(char temp[])
{
	int tempLen = Helper::stringLength(temp);

	if (posts != NULL)
	for (int i = 0 ; posts[i] != NULL ; i++)
	{
		int PIDlen = Helper::stringLength(posts[i]->getID());
		if (tempLen == PIDlen)
		{
			int var1 = Helper::compareString(posts[i]->getID(), temp);
		
			if (var1 == 0)
			return posts[i];
		}
	}

	return nullptr;

}

void facebook:: setCurrentUser(char* temp)
{
	int tempIndex = Helper::returnIndexOfobjectId(temp);

	if (tempIndex < users::totalUsers && tempIndex >= 0)
	{
		currentUser = Users[tempIndex];
		currentUser->printName();
		cout << " successfully set as current user.\n";
	}

	else cout << "User not found !\n";

}

void facebook::LoadPages(char* filename)
{
	ifstream fin;
	fin.open(filename);

	fin >> pages::totalPages;

	Pages = new pages*[pages::totalPages];		 

	int i = 0;
	while (!fin.eof())
	{
		Pages[i] = new pages;
		Pages[i]->ReadPageFromFile(fin);
		i++;
	}
}

void facebook::LoadUsers(char* filename)
{
	ifstream fin;
	fin.open(filename);

	fin >> users::totalUsers;

	Users = new users*[users::totalUsers];
	
	int i = 0;
	char tempBuffer[30];
	char*** tempFriends;

	tempFriends = new char**[20];

	while (!fin.eof())
	{
		tempFriends[i] = new char* [10];
		int j = 0;
		Users[i] = new users;
		Users[i+1] = NULL;
		Users[i]->ReadUsersFromFile(fin,tempFriends[i]);

		int x = 0;
		fin >> tempBuffer;

		if (Helper::compareString(tempBuffer,"-1"))
		{
			while (Helper::compareString(tempBuffer,"-1"))
			{
				Users[i]->likePage(searchPageById(tempBuffer));
				fin >> tempBuffer;
			}
		}
		j++;
		i++;
	}
	fin.close();

	for (int m = 0 ; m < 20 ; m++) 
		for (int n = 0 ; tempFriends[m][n] != NULL ; n++)
			Users[m]->addFriend(searchUserById(tempFriends[m][n]));

	for (int i = 0 ; i < 20 ; i++)		// Destructor for char** tempFriends
		for (int j = 0 ; tempFriends[i][j] != NULL ; j++)
			delete[] tempFriends[i][j];
	delete[] tempFriends;

}

void facebook::LoadPosts(char* filename)
{
	ifstream fin;
	fin.open(filename);
	char tempBuffer[100];

	fin >> Post::totalPosts;

	posts = new Post* [Post::totalPosts];

	for (int i = 0 ; i < Post::totalPosts ; i++)
	{
		posts[i] = new Post;
		posts[i]->ReadPostsFromFile(fin);

		fin >> tempBuffer;
		if (tempBuffer[0] != '-')
		{
			char* randomID = Helper::stringCopy(tempBuffer, Helper::stringLength(tempBuffer));

			if (randomID[0] == 'u')
				posts[i]->setShared(searchUserById(randomID));
			if (randomID[0] == 'p')
				posts[i]->setShared(searchPageById(randomID));
		}
		else posts[i]->setShared(nullptr);

		fin >> tempBuffer;
		if (tempBuffer[0] != '-')
		while (tempBuffer[0] != '-')
		{
			char* randomID = Helper::stringCopy(tempBuffer, Helper::stringLength(tempBuffer));

			if (randomID[0] == 'u')
				posts[i]->setLiked(searchUserById(randomID));
			if (randomID[0] == 'p')
				posts[i]->setLiked(searchPageById(randomID));
		
			fin >> tempBuffer;
		}
		else posts[i]->setLiked(nullptr);
	}

	fin.close();
}

void facebook::LoadComments(char* filename)
{
	ifstream fin;
	fin.open(filename);

	if(fin.is_open())
	{
		fin >> Comment::totalComments;

		comments = new Comment* [Comment::totalComments];
		for (int i = 0 ; i < Comment::totalComments ; i++)
		{
			comments[i] = new Comment;
			
			char tempBuffer[100];
			
			fin >> tempBuffer;

			comments[i]->setID(Helper::GetStringFromBuffer(tempBuffer));

			fin >> tempBuffer;
			
			Post* myPost = searchPostById(tempBuffer);
			myPost->addComment(comments[i]);

			fin >> tempBuffer;

			object* commentedBy = searchObjectById(tempBuffer);
			comments[i]->setCommentator(commentedBy);

			fin.ignore();
			fin.getline(tempBuffer,100);
			comments[i]->setText(tempBuffer);
		}
		fin.close();
	}
	else cout << "File not found !\n";

	
}

void facebook :: LoadData(char* pagefile, char* userfile, char* postFile, char* commentsFile)
{
	facebook::LoadPages(pagefile);
	facebook::LoadUsers(userfile);
	facebook::LoadPosts(postFile);
	facebook::LoadComments(commentsFile);

	for (int i = 0 ; i < Post::totalPosts ; i++)	// adding posts after all the above are loaded into memory.
	{
		int tempIndex = Helper::returnIndexOfobjectId(posts[i]->getShared()->getID());

		if (posts[i]->getShared()->getID()[0] == 'u')
			Users[tempIndex]->addPost(posts[i]);

		if (posts[i]->getShared()->getID()[0] == 'p')
			Pages[tempIndex]->addPost(posts[i]);
	}
}

void facebook:: Run()
{
	cout << "------------------------------------------------------------------------------------"<< endl;	
	cout << "Command:\tSet current user u7 "<< endl; 
	cout << "------------------------------------------------------------------------------------"<< endl;

	setCurrentUser("u7");
	
	cout << "------------------------------------------------------------------------------------"<< endl;
	cout << "Command:\tSet current System Date (15/11/2017)\n"; 
	cout << "------------------------------------------------------------------------------------"<< endl;

	Date::setCurrentDate(15, 11, 2017); 

	cout << "System Date:\t"; Date::currentDate.Print(); 

	cout << endl;
	
	if (currentUser != NULL)
	{
		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Friend List\n";
		cout << "------------------------------------------------------------------------------------"<< endl;
		currentUser->displayFriendList(); 

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Liked Pages\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->displayLikedPages();

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Home\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->printHomepage();

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Time Line\n";
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->printTimeline(); 

		cout << endl;
		cout << endl;

		int index;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Liked List(Post 5)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		index = Helper::returnIndexOfobjectId("post5"); 
		posts[index]->showLiked(); 

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tLike Post(Post 5)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		posts[index]->setLiked(currentUser); 

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command: \tView Liked List(Post 5)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		posts[index]->showLiked();
		
		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tPostComment(Post 4, Good Luck for your Result)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		Comment *comment = new Comment("Good Luck for your Result", currentUser); 
		index = Helper::returnIndexOfobjectId("post4"); 
		posts[index]->addNewComment(comment); 

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Post(Post 4)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;
		posts[index]->printDetailedView();

		cout << endl;
		
		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tPostComment(Post 8, Thanks for the wishes)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;
		comment = new Comment("Thanks for the wishes", currentUser); 
		index = Helper::returnIndexOfobjectId("post8"); 
		posts[index]->addNewComment(comment);

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Post(Post 8)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		index = Helper::returnIndexOfobjectId("post8");
		posts[index]->printDetailedView();
		
		cout << endl;
		cout << endl;

		/*currentUser->setMemory(Date::currentDate);*/

		/*Post* tempPost = searchPostById("post10");
		object* tempobj = tempPost->getShared();
		currentUser->shareMemory("post10", "Never thought i would be specialist in this field !", tempobj);*/

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tAdd post to timeline of u7\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->addPost(posts[index]);

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView TimeLine\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->printTimeline();
		
		cout << endl;
		cout << endl;
		
		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Page(p1)\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		index = Helper::returnIndexOfobjectId("p1"); 
		Pages[index]->printTimeline(); 
		
		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;	
		cout << "Command:\tSet current user u11 "<< endl; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		setCurrentUser("u11");

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Home\n"; 
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->printHomepage();

		cout << endl;
		cout << endl;

		cout << "------------------------------------------------------------------------------------"<< endl;
		cout << "Command:\tView Time Line\n";
		cout << "------------------------------------------------------------------------------------"<< endl;

		currentUser->printTimeline(); 


	}

	else cout << "No user found by such ID.\n";
}

int main ()
{
{	facebook fb;
	fb.LoadData("Pages.txt", "Users.txt", "Posts.txt", "Comments.txt");

	fb.Run();
}
	system("pause");
	return 0;
}