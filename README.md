# comictracker
 sort and track books and comics
## installation
```
git clone https://github.com/Hauptling12/comictracker
cd comictracker && mkdir ~/.local/share/comictracker/ && cp book.json comic.json ~/.local/share/comictracker/
gcc comictracker.c -ljson-c -o comictracker && gcc booktracker.c -ljson-c -o booktracker
cp comictracker booktracker ~/.local/bin
```
## man page
+ `-a` add comics
+ `-l` list comics
+ `-h` show the man page
