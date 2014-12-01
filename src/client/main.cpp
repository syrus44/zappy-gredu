//
// main.cpp for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by antoine dugast
// Login   <dugast_a@epitech.net>
// 
// Started on  Fri Jun 28 15:04:51 2013 antoine dugast
// Last update Sat Jun 29 14:02:07 2013 louis cailleux
//

#include	"Ia.hh"
#include	"Exception.hh"
#include	"Parser.hh"
#include	"Network.hh"

int		main(int ac, char **av)
{
  std::string args = "";
  try
    {
      if (ac > 1 && ac < 8)
  	{
	  for (int i = 1; av[i]; ++i)
	    {
   	      args += av[i];
   	      args += " ";
   	    }
   	  Parser *p = new Parser(args);
   	  p->checkCommands();

   	  Network *nw = new Network(p);
   	  nw->tryToConnect();
   	  nw->play();
   	}
       else
   	throw Exception("Usage: ./client -n [team name] -p [port] -h [machine name]");
     }
  catch (const Exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  return (0);
}
