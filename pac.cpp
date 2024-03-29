#include <cstdio>
#include <string>
#include <cstdlib>

#define elif else if
using namespace std;

void show_help()
{
	printf("Usage :-\n"
				"pac [operation] <pkg list>\n"
				"\n"
				"install/add    --> Install the specified program.\n"
				"remove/delete  --> Removes the specified program with dependencies.\n"
				"search/find    --> Searches for a package in package lists.\n"
				"refresh/sync   --> Refreshes package lists.\n"
				"upgrade/update --> Updates all packages to latest version.\n"
				"clean/tidy     --> Removes cached package downloads.\n"
				"\n"
				"Note: You can also pass flags directly to pacman. eg. pac -Syu\n");
}

string tok2str(int cnt, const char* tok[], const char* delim)
{
	string str;
	for (int i=0 ; i < cnt ; ++i)
	{
		str += tok[i];
		if (i < cnt-1) str += delim;
	}
	return str;
}

int main(int argc, const char* argv[])
{
	string pkgs;
	
	switch (argc)
	{
	case 1: // no argument provided
	  show_help();
		return -1;
	
	case 2: // no package names provided
	  pkgs = "";
	  break;
	
	default: // package names provided
	  pkgs = tok2str(argc-2, &argv[2], " ");
	}
	
	string cmd = argv[1];
	
	if (cmd[0] == '-') // pass directly to pacman
	{
		system(("pacman " + cmd + ' ' + pkgs).c_str());
	}
	elif (cmd == "install" || cmd == "add")
	{
		system(("pacman -Sy " + pkgs).c_str());
	}
	elif (cmd == "remove" || cmd == "delete")
	{
		system(("pacman -Rs " + pkgs).c_str());
	}
	elif (cmd == "search" || cmd == "find")
	{
		system(("pacman -Ss "s + argv[2]).c_str());
	}
	elif (cmd == "refresh" || cmd == "sync")
	{
		system("pacman -Sy");
	}
	elif (cmd == "upgrade" || cmd == "update")
	{
		system(("pacman -Syu " + pkgs).c_str());
	}
	elif (cmd == "clean" || cmd == "tidy")
	{
		system("paccache -rk0"); 			 // prune all cache
		system("paccache -rk1 > /dev/null"); // keep 1 version
	}
	else
	{
		show_help();
		return -1;
	}
}
