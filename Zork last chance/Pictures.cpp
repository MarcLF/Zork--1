#include <iostream>
#include "World.h"

//Items
void World::Pictures(MyString&input) const
{
	if (((Item*)entity[43])->taken == true && ((Item*)entity[43])->name == input)
	{
		printf(R"EOF(
||====================================================================||
||//$\\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//$\\||
||(100)==================| RESERVE BANK OF INDIA|================(100)||
||\\$//        ~         '------========--------'                \\$//||
||<< /        /$\              // ____ \\                         \ >>||
||>>|        //L\\            // ///..) \\              XXXX       |<<||
||<<|        \\ //           || <||  >\  ||                        |>>||
||>>|         \$/            ||  $$ --/  ||          XXXXXXXXX     |<<||
||<<|     Free to Use        *\\  |\_/  //*                        |>>||
||>>|                         *\\/___\_//*                         |<<||
||<<\      Rating: E     _____/ M GANDHI \________    XX XXXXX     />>||
||//$\                 ~|    REPUBLIC OF INDIA   |~               /$\\||
||(100)===================   ONE HUNDRED RUPEES =================(100)||
||\\$//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\$//||
||====================================================================||
)EOF");
	}
	else if (((Item*)entity[44])->taken == true && ((Item*)entity[44])->name == input)
	{
		printf(R"EOF(
 ad8888888888ba 
dP'         `"8b, 
8  ,aaa,       "Y888a     ,aaaa,     ,aaa,  ,aa, 
8  8' `8           "8baaaad""""baaaad""""baad""8b  
8  8   8              """"      """"      ""    8b 
8  8, ,8         ,aaaaaaaaaaaaaaaaaaaaaaaaddddd88P 
8  `"""'       ,d8"" 
Yb,         ,ad8" 
 "Y8888888888P" 

)EOF");
	}
	else if (((Item*)entity[45])->taken == true && ((Item*)entity[45])->name == input)
	{
		printf(R"EOF(
        _______
    ___/_____ _)____
 .-'-'   ____)______)
|    .-'    ______)__)
|    ---    _______))
|    `-.   _______))
 `---.___________)

)EOF");
	}
	else if (((Item*)entity[46])->taken == true && ((Item*)entity[46])->name == input)
	{
		printf(R"EOF(
   .eec.              .e$$$c                                
  z$*"*$$eec..       zP  .3$c                  
 .$"  d$"  """****bee*=*"" *$                               
 $%  d$$                  ^$%                              
.$  z$%$bc.                 $%                              
4F 4$" $"^$*ec..  .ee.    ./" b                             
dF $P  P  F   """""3F""""""   4                             
3b4$   "           $F         4                             
4$$$  -            $F         4                             
 $$$               $F         4                             
 *$$               $F         @                             
 4$$               $F         F                             
 ^$F   .......     $F        .F                             
  $"  z"     ^"""""$F"""""""""%.                            
 4$  4F     e      $L          ".                           
 4F  ^L    4$     z%"c    *.    b                           
 d    ^$*=e$$eer=$"  "be..JL..ee*                           
 $     $   $F    $   zP   4P   F                            
 F     F   $F    4. .P    d%  J                             
4%     F   $F     F $"   zP   P                             
J      F   '%     Fd"   4P   4"                             
$      F          $F         P                              
$      L         .$         4%                              
*      '.       .$$.       .$                               
'       ^"****"""  "*******$"                               
 %                        .P                                
  *c                     .@                                 
   ^"%4c...        ...dw*                         
         ^""""""""
)EOF");
	}
}