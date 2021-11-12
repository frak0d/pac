# pac
Do you wanna ***Arch BTW*** but can't remember those pesky pacman commands ? Behold **pac** ! a simplified frontend to pacman.

### Usage :-
```
pac [operation] <pkg list>
install        --> Install the specified program.           remove/delete  --> Removes the specified program with dependencies.
search/find    --> Searches for a package in package lists.
refresh/sync   --> Refreshes package lists.
upgrade/update --> Updates all packages to latest version.
clean          --> Removes cached package downloads.
```

**Note:** Multiple aliases are provided for same tasks. For Example, `pac refresh` and `pac sync` are equivalent and is just a matter of personal preference.

### Installation :-
1. `git clone https://github.com/frak0d/pac`
2. `sudo g++ -O2 -s pac/main.cpp -o /usr/bin/pac && rm -r pac`

### Uninstallation :-
1. `sudo rm /usr/bin/pac`
