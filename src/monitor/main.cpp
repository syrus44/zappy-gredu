//
// main.cpp for zappy in /home/caille_l//Documents/client
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu May  9 16:24:56 2013 louis cailleux
// Last update Sun Jul 14 16:35:58 2013 pierre petit
//

#include "Exception.hh"
#include "Parser.hh"
#include "Network.hh"

int	main(int ac, char **av)
{
  std::string args = "";
  try
    {
      if (ac > 1 && ac < 6)
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
	throw Exception("Usage: ./monitor -p [port] -h [machine name]");
    }
  catch (const Exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  return (0);
}
