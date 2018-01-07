#include <ncurses.h>

int lauchMenu()
        {

          const char *array[]={"Pacman", "Snake"};
          int selection = 0;
          int row=1;
          int col=2;
          int length=2;
          int width=50;
          int menulength=50;

        int counter,offset=0,ky=0;
        char formatstring[7];
        curs_set(0);

        if (length < menulength)
                menulength=length;

        if (selection > menulength)
                offset=selection-menulength+1;

        sprintf(formatstring,"%%-%ds",width);

        while(ky != 27)
                {
                for (counter=0; counter < menulength; counter++)
                        {
                        if (counter+offset==selection)
                                attron(A_REVERSE);
                        mvprintw(row+counter,col,formatstring,array[counter+offset]);
                        attroff(A_REVERSE);
                        }

                ky=getch();

                switch(ky)
                        {
                        case  50:
                          refresh();
                          return (0);
                          break;
                        case  51:
                          refresh();
                          return (1);
                          break;
                        case  52:
                          refresh();
                          return (2);
                          break;
                        case  53:
                          refresh();
                          return (3);
                          break;
                        case  56:
                          refresh();
                          break;
                        case  57:
                          refresh();
                          break;
                        case KEY_UP:
                                if (selection)
                                        {
                                        selection--;
                                        if (selection < offset)
                                                offset--;
                                        }
                                break;
                        case KEY_DOWN:
                                if (selection < length-1)
                                        {
                                        selection++;
                                        if (selection > offset+menulength-1)
                                                offset++;
                                        }
                                break;
                        case KEY_HOME:
                                selection=0;
                                offset=0;
                                break;
                        case KEY_END:
                                selection=length-1;
                                offset=length-menulength;
                                break;
                        case KEY_PPAGE:
                                selection-=menulength;
                                if (selection < 0)
                                        selection=0;
                                offset-=menulength;
                                if (offset < 0)
                                        offset=0;
                                break;
                        case KEY_NPAGE:
                                selection+=menulength;
                                if (selection > length-1)
                                        selection=length-1;
                                offset+=menulength;
                                if (offset > length-menulength)
                                        offset=length-menulength;
                                break;
                        case 10: //enter
                                return selection + 10;
                                break;
                        case 27:
                          return (4);
                        }
                }
        return -1;
}

extern "C" int makeMenu()
    {
    int s;
    initscr();
    noecho();
    keypad(stdscr,TRUE);
    mvprintw(20, 20,"Arcade");
    s = lauchMenu();

    refresh();
    getch();

    endwin();
    return (s);
}
