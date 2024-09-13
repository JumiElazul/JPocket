#include "application.h"

namespace JPocket
{

	int main(int argc, char* argv[])
	{
        application app;
        return app.run();
	}

}

int main(int argc, char* argv[])
{
	return JPocket::main(argc, argv);
}
