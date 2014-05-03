Using this code you can set your reminder clock in a file with time and a message.
at that time a Qt window will open with that message.

so what you have to do is :


put this code in '.profile' file , which is a hidden file at home ( if it doesn't exist then create it)


num=$(Documents/impthing/clock num);
num=$(($num-1));
for i in $(seq 0 $num ) ;
do
        (sleep $(Documents/impthing/clock tim $i)s ; (Documents/impthing/proj5 "$(Documents/impthing/clock g $i ) <br> it is `date +%H:%M`  " ) ) &
done


put the 'clock' file  (which is made by compilation of clock.cpp file) , in Documents/impthing folder ( or change the path from .profile file)
put the 'proj5' file at "Documents/impthing/" which is compiled by proj5.cpp file.


now set all your alarm in .time file , which is hidden file at home , using this formate , where line starting with '>' is
not set as alarm( acts like comment).

185530| go to dinner, it is time of it
>181500| go for long kriya,  old kailash
184000| goint  at III363
000000| it's time of going to hostel. ... go .
230000| go to hostel sleep well ...



when you login computer then alarm will already in process , so that when time comes it displayes message.
