#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bugstack_node {
	char *name;
	struct bugstack_node *next;
};
struct bugstack_node *bug_stack = 0;

void push_bug(char *name){
	struct bugstack_node *new_bug = malloc(sizeof(struct bugstack_node));
	new_bug->name = malloc(strlen(name) + 1);
	strcpy(new_bug->name, name);
	new_bug->next = bug_stack;
	bug_stack = new_bug;
}

void free_bugs(struct bugstack_node* place){
	if(!place)
		return;	
	free_bugs(place->next);
	free(place->name);
	free(place);
}

/* print_bugs prints out the name of each bug in the stack.  You can 
 * use printf or write or puts or whatever you need to do the actual
 * printing */
void print_bugs(void*);

/* halves_to_100 returns the number of times the parameter can be divided in
 * half before the result is less than 100.  So if the number was 260.8, dividing
 * once would be 130.4, and twice would be 65.2.  Therefore the result is 2. */
long halves_to_100(double);

/* return_five_returner returns the memory address of a different function.
 * The function it returns the address of should, when called with no parameters,
 * return a 5 (as an integer type, not floating point). */
int (*return_five_returner())();

/* space_to_underscore should convert all the spaces in the null-terminated
 * string to underscores.  It should edit the string its given the address
 * of, not make a copy.  You don't have to set rax before returning since
 * it returns void */
void space_to_underscore(char*);

int main(){
	push_bug("Termite");
	push_bug("Mayfly");
	push_bug("Water Strider");
	push_bug("Moth");
	push_bug("Dragonfly");
	push_bug("Mantis");
	print_bugs(bug_stack);
	free_bugs(bug_stack);

	printf("halves_to_100(437) returns %d\n", halves_to_100(437)); // Should be 3
	printf("halves_to_100(1837) returns %d\n", halves_to_100(1837)); // Should be 5
	printf("halves_to_100(100.1) return %d\n", halves_to_100(100.1)); // Should be 1
	printf("halves_to_100(89.2) return %d\n", halves_to_100(89.2)); // Should be 0

	/* The second set of () is deliberate - return_five_returner returns a function,
 	 * and this code calls the function it returns  */
	if(return_five_returner()() == 5)
		printf("Got it!\n");
	else
		printf("Not yet!\n");

	char phrase[] = "This phrase has spaces.";
	space_to_underscore(phrase);
	printf("With the spaces replaced by underscores:\n%s\n", phrase);

	
	return 0;
}