#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	//Go through options
	char opt;
	while((opt = getopt(argc, argv, "ab:")) != EOF){
		switch (opt){
			case 'a':
				printf("a is present\n");
				break;
			case 'b':	//Optarg is from getopt
				printf("b is present with value %s\n", optarg);
				break;
			default:
				printf("Unknown option: %s\n", optarg);
		}
	}

	argc -= optind; //Decrease the count, optind is from getopt 
	argv += optind;

	printf("Arg count: %i", argc);

	return 0;
}
