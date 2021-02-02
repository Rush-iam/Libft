void check_1(void); void check_2(void); void check_3(void); void check_4(void);
void check_5(void);
char mapicheck(unsigned index, char c);
void listdel(void *s); void listiter(void *s); void *listmapper(void *s);
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
int	main(void)
{
//	char mem4[] = "123456789012345678901234567890";
//	printf("\n%s\n", ft_memset(mem4, 'Z' + 256, 28));
	clock_t start, end;
	char src[] = "435184518rfn hjrbfl isuh rhhksbrkfhbskhdrb fsb r342z23424233212!234";
	char src2[] = " 435184518rfn hjrbfl isuh rhhksbrkfhbskhdrb fsb r342z23424233212?234";
	#define CHECK src, src2+1, 68
	start = clock();
	for (int i = 0; i < 60000000; ++i){ft_memcmp(CHECK);}
	end = clock();
	printf("\n%.3f, %d = %d", (double)(end - start) / CLOCKS_PER_SEC,
		   ft_memcmp(CHECK), memcmp(CHECK));

	//while (1){
//		check_1();
//		check_2();
//		check_3();
	//	check_4();
	//	check_5();
	//	sleep(1);
	//}
}

void check_1(){
	printf("isalpha 1=%d, 1=%d, 1=%d, 1=%d, 0=%d, 0=%d, 0=%d, 0=%d\n\n",
		ft_isalpha('A'), ft_isalpha('Z'), ft_isalpha('a'), ft_isalpha('z'),
		ft_isalpha('@'), ft_isalpha('['), ft_isalpha('`'), ft_isalpha('{'));

	printf("isdigit 0=%d, 0=%d", ft_isdigit('/'), ft_isdigit(':'));
	for (int i=0; i<10; i++)
		printf(", 1=%d", ft_isdigit('0' + i));

	printf("\n\nisalnum 1=%d, 1=%d, 1=%d, 1=%d, 0=%d, 0=%d, 0=%d, 0=%d\n",
		   ft_isalnum('A'), ft_isalnum('Z'), ft_isalnum('a'), ft_isalnum('z'),
		   ft_isalnum('@'), ft_isalnum('['), ft_isalnum('`'), ft_isalnum('{'));
	printf("0=%d, 0=%d", ft_isalnum('/'), ft_isalnum(':'));
	for (int i=0; i<10; i++)
		printf(", 1=%d", ft_isalnum('0' + i));

	printf("\n\nisascii\n0=%d, 0=%d", ft_isascii(-1), ft_isascii('\220'));
	for (int i = 0; i < 128; ++i){
		if (!(i%64))
			printf("\n");
		printf("%d", ft_isascii(i));}

	printf("\n\nisprint\n0=%d, 0=%d", ft_isprint(31), ft_isprint(127));
	for (int i = 32; i < 127; ++i){
		if (!((i-32)%48))
			printf("\n");
		printf("%d", ft_isprint(i));}

	printf("\n\ntoupper\nA=%c, Z=%c, `=%c, {=%c\n",
		ft_toupper('A'), ft_toupper('Z'), ft_toupper('`'), ft_toupper('{'));
	for (int i = 97; i < 123; ++i)
		printf("%c", ft_toupper(i));

	printf("\n\ntolower\na=%c, z=%c, @=%c, [=%c\n",
		   ft_tolower('a'), ft_tolower('z'), ft_tolower('@'), ft_tolower('['));
	for (int i = 65; i < 91; ++i)
		printf("%c", ft_tolower(i));
}

void check_2()
{
	printf("\n\nstrlen 0=%zu, 1=%zu, 11=%zu\n\n",
		   ft_strlen(""), ft_strlen("k"), ft_strlen("hello world"));

	char d1[10] = "", d2[10] = "", *s1 = "Hello";
	printf("strlcpy\n");
	for (int i = 0; i < 8; ++i){
		printf("i%dr%zu s=%s; ", i, strlcpy(d1, s1, i), d1);}
	for (int i = 0; i < 8; ++i){if (!i) printf("\n");
		printf("i%dr%zu s=%s; ", i, ft_strlcpy(d2, s1, i), d2);}
	printf("\nr=%zu, s=%s; r=%zu;", strlcpy(d1, s1, 0), d1, strlcpy(0, s1, 0));
	printf("\nr=%zu, s=%s; r=%zu;", ft_strlcpy(d2, s1, 0), d2, ft_strlcpy(0, s1, 0));

	char d3[10] = "Go", d4[10] = "Go", *s2 = "HoK";
	printf("\n\nstrlcat\n");
	for (int i = 0; i < 8; ++i){
		strcpy(d3, "Go");
		printf("s%dr%zu s=%s; ", i, strlcat(d3, s2, i), d3);}
	for (int i = 0; i < 8; ++i){if (!i) printf("\n");
		strcpy(d4, "Go");
		printf("s%dr%zu s=%s; ", i, ft_strlcat(d4, s2, i), d4);}
	printf("\nr=%zu, s=%s; r=%zu, s=%s; r=%zu;",
		   strlcat(d3, "", 7), d3, strlcat(d3, s2, 0), d3, strlcat(0, s2, 0));
	printf("\nr=%zu, s=%s; r=%zu, s=%s; r=%zu;\n\n",
		   ft_strlcat(d4, "", 7),d4,ft_strlcat(d4,s2,0),d4,ft_strlcat(0,s2,0));

	char *a = "abc";
	printf("strchr\n%s=%s; %s=%s; %s=%s; %s=%s; %p=%p; 0%s=0%s\n\n",
		   strchr(a, 'a'), ft_strchr(a, 'a'),	strchr(a, 'b'+256), ft_strchr(a, 'b'+256),
		   strchr(a, 'c'), ft_strchr(a, 'c'),	strchr(a, 'z'), ft_strchr(a, 'z'),
		   strchr(a, 0), ft_strchr(a, 0),	strchr("", 0), ft_strchr("", 0));

	char *b = "abca";
	printf("strrchr\n%s=%s; %s=%s; %s=%s; %s=%s; %p=%p; 0%s=0%s\n\n",
		   strrchr(b, 'a'), ft_strrchr(b, 'a'),	strrchr(b, 'b'+256), ft_strrchr(b, 'b'+256),
		   strrchr(b, 'c'), ft_strrchr(b, 'c'),	strrchr(b, 'z'), ft_strrchr(b, 'z'),
		   strrchr(b, 0), ft_strrchr(b, 0),	strrchr("", 0), ft_strrchr("", 0));

	char *empty = "";
	printf("strnstr\n%s=%s; %s=%s; %s=%s; %s=%s; %s=%s;\n%s=%s; %s=%s; %s=%s; %p=%p; %s=%s;\n\n",
		   strnstr("Foo Bar2", "Bar", 8), ft_strnstr("Foo Bar2", "Bar", 8),
		   strnstr("Foo Bar2", "Bar", 7), ft_strnstr("Foo Bar2", "Bar", 7),
		   strnstr("Foo Bar2", "Bar", 6), ft_strnstr("Foo Bar2", "Bar", 6),
		   strnstr("Foo Bar2", "", 3), ft_strnstr("Foo Bar2", "", 3),
		   strnstr("Foo Bar", "r", 10), ft_strnstr("Foo Bar", "r", 10),
		   strnstr("Foo Bar", "r", 7), ft_strnstr("Foo Bar", "r", 7),
		   strnstr("Foo Bar2", "Bar", 0), ft_strnstr("Foo Bar2", "Bar", 0),
		   strnstr(0, "Bar", 0), ft_strnstr(0, "Bar", 0),
		   strnstr(empty, "", 4), ft_strnstr(empty, "", 4),
		   strnstr("", "Bar", 4), ft_strnstr("", "Bar", 4));

	printf("strncmp (sign matters)\n");
	for (int i = 0; i < 6; ++i){
		printf("%d) %d=%d; ", i, strncmp("abc", "abc", i), ft_strncmp("abc", "abc", i));}
	for (int i = 3; i < 6; ++i){
		printf("%d) %d=%d; ", i, strncmp("abcz", "abcd", i), ft_strncmp("abcz", "abcd", i));}
	printf("\n%d=%d, %d=%d, %d=%d, %d=%d, %d=%d, %d=%d, %d=%d\n\n",
		   strncmp("abc", "abc", 0), ft_strncmp("abc", "abc", 0),
		   strncmp("abc", "zbc", 1), ft_strncmp("abc", "zbc", 1),
		   strncmp("abc", "", 5), ft_strncmp("abc", "", 5),
		   strncmp("", "abc", 5), ft_strncmp("", "abc", 5),
		   strncmp(0, "abc", 0), ft_strncmp(0, "abc", 0),
		   strncmp("abc", 0, 0), ft_strncmp("abc", 0, 0),
//		strncmp(0, "abc", 5), ft_strncmp(0, "abc", 5),
//		strncmp("abc", 0, 5), ft_strncmp("abc", 0, 5),
		   strncmp(0, 0, 0), ft_strncmp(0, 0, 0));

	printf("atoi\n%d=%d; %d=%d; %d=%d; %d=%d; %d=%d; %d=%d; %d=%d; %d=%d; %d=%d\n",
		   atoi("42"), ft_atoi("42"), atoi("0"), ft_atoi("0"), atoi(""), ft_atoi(""),
		   atoi("\t  -5"), ft_atoi("\t  -5"), atoi("- 42"), ft_atoi("- 42"),
		   atoi("\n\t\v  \r+7"), ft_atoi("\n\t\v  \r+7"), atoi("-00"), ft_atoi("-00"),
		   atoi("\f+023-2"), ft_atoi("\f+023-2"), atoi("00000000 3"), ft_atoi("00000000 3"));
	printf("%d = %d, %d = %d\n%d = %d, %d = %d\nit's ok: %d=%d, %d=%d, %d=%d, %d=%d\n\n",
		   atoi("-0002147483648"), ft_atoi("-0002147483648"),
		   atoi("0002147483647"), ft_atoi("0002147483647"),
		   atoi("2147483650"), ft_atoi("2147483650"),
		   atoi("-2147483650"), ft_atoi("-2147483650"),
		   atoi("-9223372036854775828"), ft_atoi("-9223372036854775828"),
		   atoi("-9223372036854775809"), ft_atoi("-9223372036854775809"),
		   atoi("9223372036854775828"), ft_atoi("9223372036854775828"),
		   atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
}

void check_3()
{

	char mem0[] = "Hello", mem1[] = "Hello"; int m0 = 0;
	printf("memset\n%s=%s; ", memset(0, 'z', m0), ft_memset(0, 'z', m0));
	for (int i = 0; i < 6; ++i){
		printf("%s=%s; ", memset(mem0, 'Z', i), ft_memset(mem1, 'Z', i));}
	printf("\nempty%s=empty%s; %d=%d; %c=%c; ",
		   memset(mem0, 0, 3), ft_memset(mem1, 0, 3), mem0[2], mem1[2], mem0[3], mem1[3]);
	printf("%s=%s; %d=%d\n\n",
		   memset(mem0, 200, 3), ft_memset(mem1, 200, 3), mem0[1], mem1[1]);

	char mem2[] = "Hello", mem3[] = "Hello"; bzero(mem2, m0); ft_bzero(mem3, m0);
	printf("bzero\n%s=%s; ", mem2, mem3); bzero(mem2+2, 2); ft_bzero(mem3+2, 2);
	printf("%s=%s; %c=%c; %d=%d\n\n", mem2, mem3, mem2[4], mem3[4], mem2[3], mem3[3]);

	char mem4a[] = "PRIVET", mem4b[] = "PRIVET";
	printf("memcpy\n%s=%s; %s=%s\n", memcpy(0, 0, 0), ft_memcpy(0, 0, 0),
		   memcpy(0, 0, 5), ft_memcpy(0, 0, 5));
	printf("overlap dst<src OK %s -> ", mem4a); printf("%s\n", memcpy(mem4a, mem4a+2, 3));
	printf("overlap dst<src MY %s -> ", mem4b); printf("%s\n", ft_memcpy(mem4b, mem4b+2, 3));
	printf("overlap dst>src OK %s -> ", mem4a); printf("%s\n", memcpy(mem4a+2, mem4a, 3));
	printf("overlap dst>src MY %s -> ", mem4b); printf("%s\n", ft_memcpy(mem4b+2, mem4b, 3));
	for (int i = 0; i < 7; ++i){
		printf("%s=%s ", memcpy(mem4a, "poka!", i), ft_memcpy(mem4b, "poka!", i));}
	printf("\nempty%s=empty%s; %c=%c\n\n",
		   memcpy(mem4a, "", 1), ft_memcpy(mem4b, "", 1), mem4a[1], mem4b[1]);

	char mem5a[] = "TestStr", mem5b[] = "TestStr";
	printf("memccpy\n%s=%s; %s=%s & %s=%s; ", memccpy(0,0,0,0), ft_memccpy(0,0,0,0),
		   memccpy(mem5a, "Z", 0, 2), ft_memccpy(mem5b, "Z", 0, 2), mem5a, mem5b);
	printf("%s=%s & %s=%s;\n%s=%s & %s=%s;  %s=%s & %s=%s;\n",
		   memccpy(mem5a, "Test", 'a', 4), ft_memccpy(mem5b, "Test", 'a', 4), mem5a, mem5b,
		   memccpy(mem5a, 0, 'a', 0), ft_memccpy(mem5b, 0, 'a', 0), mem5a, mem5b,
		   memccpy(0, "QQ", 'a', 0), ft_memccpy(0, "QQ", 'a', 0), mem5a, mem5b);
	printf("%s=%s & %s=%s;\n", memccpy(mem5a, "a\310b", 200, 3),
		   ft_memccpy(mem5b, "a\310b", 200, 3), mem5a, mem5b);
	for (int i = 0; i < 7; ++i){strcpy(mem5a, "TestStr");strcpy(mem5b, "TestStr");
		printf("%d) %s=%s %s=%s;\n", i, memccpy(mem5a, "Chek", 'k'+256, i),
			   ft_memccpy(mem5b, "Chek", 'k'+256, i), mem5a, mem5b);}

	char mem6a[] = "PRIVET", mem6b[] = "PRIVET";
	printf("\nmemmove\n%s=%s; %s=%s\n", memmove(0, 0, 0), ft_memmove(0, 0, 0),
		   memmove(0, 0, 5), ft_memmove(0, 0, 5));
	printf("overlap dst>src OK %s -> ", mem6a); printf("%s\n", memmove(mem6a+1, mem6a, 3));
	printf("overlap dst>src MY %s -> ", mem6b); printf("%s\n", ft_memmove(mem6b+1, mem6b, 3));
	printf("overlap dst<src OK %s -> ", mem6a); printf("%s\n", memmove(mem6a, mem6a+1, 3));
	printf("overlap dst<src MY %s -> ", mem6b); printf("%s\n", ft_memmove(mem6b, mem6b+1, 3));
	for (int i = 0; i < 7; ++i){
		printf("%s=%s ", memmove(mem6a, "poka!", i), ft_memmove(mem6b, "poka!", i));}
	printf("\nempty%s=empty%s; %c=%c\n\n",
		   memmove(mem6a, "", 1), ft_memmove(mem6b, "", 1), mem6a[1], mem6b[1]);

	printf("memchr\n%s=%s; 0%s=0%s; %s=%s; %s=%s; %s=%s\n",
		   memchr(0, 0, 0), ft_memchr(0, 0, 0), memchr("", 0, 1), ft_memchr("", 0, 1),
		   memchr("a", 'a', 1), ft_memchr("a", 'a', 1),
		   memchr("a", 'b', 1), ft_memchr("a", 'b', 1),
		   memchr("z", 'z' + 256, 1), ft_memchr("z", 'z' + 256, 1));
	printf("%s=%s\n", memchr("abracadabra!!", '!', 13), ft_memchr("abracadabra!!", '!', 13));
	for (int i = 0; i < 4; ++i){
		printf("%d) %s=%s; ", i, memchr("Cek", 'e', i), ft_memchr("Cek", 'e', i));}

	printf("\n\nmemcmp (sign matters)\n");
	for (int i = 0; i < 6; ++i){
		printf("%d) %d=%d; ", i, memcmp("abc", "abc", i), ft_memcmp("abc", "abc", i));}
	for (int i = 3; i < 6; ++i){
		printf("%d) %d=%d; ", i, memcmp("abcz", "abcd", i), ft_memcmp("abcz", "abcd", i));}
	printf("\n%d=%d, %d=%d, %d=%d, %d=%d, %d=%d, %d=%d, %d=%d\n\n",
		   memcmp("abc", "abc", 0), ft_memcmp("abc", "abc", 0),
		   memcmp("abc", "xbc", 1), ft_memcmp("abc", "xbc", 1),
		   memcmp("abc", "", 5), ft_memcmp("abc", "", 5),
		   memcmp("", "abc", 5), ft_memcmp("", "abc", 5),
		   memcmp(0, "abc", 0), ft_memcmp(0, "abc", 0),
		   memcmp("abc", 0, 0), ft_memcmp("abc", 0, 0),
//		memcmp(0, "abc", 5), ft_memcmp(0, "abc", 5),
//		memcmp("abc", 0, 5), ft_memcmp("abc", 0, 5),
		   memcmp(0, 0, 0), ft_memcmp(0, 0, 0));

	long *cal1a = calloc(200, 8), *cal1b = ft_calloc(200, 8), *cal0b = ft_calloc(0, 0);
	printf("calloc\n%ld = %ld; %ld = %ld; ", cal1a[0], cal1a[1], cal1b[0], cal1b[1]);
	printf("not null = %p; ", cal0b); for (int i=0; i<200; ++i){cal1b[i] = 3;}
	printf("3 = %ld\nZeroes:", cal1b[199]); free(cal1b); cal1b = ft_calloc(200, 8);
	for (int i=0; i<200; ++i){if (!(i%100)) printf("\n"); printf("%ld", cal1b[i]);}
	free(cal1a); free(cal1b); free(cal0b);

	char *dup1a = strdup(""), *dup1b = ft_strdup(""),
			*dup2a = strdup("Hi"), *dup2b = ft_strdup("Hi");
	printf("\n\nstrdup\n0%s=0%s; %s=%s;\n", dup1a, dup1b, dup2a, dup2b);
	free(dup2a); free(dup2b); dup2b = ft_strdup("H"); printf("H=%s", dup2b);
	free(dup1a); free(dup1b); free(dup2b);
}

void check_4()
{

	char *sub1 = ft_substr("Test", 0, 7), *sub2 = ft_substr("Test2", 3, 1),
			*sub3 = ft_substr("", 0, 1);
	printf("\n\nsubstr\nTest=%s; t=%s; 0=%d;\n", sub1, sub2, *sub3);
	free(sub1); free(sub2); free(sub3);

	char *j1 = ft_strjoin("Hi ", "all!"), *j2 = ft_strjoin("", ""),
			*j3 = ft_strjoin("1", "2");
	printf("\nstrjoin\nHi all!=%s; 0=%d; 12=%s\n", j1, *j2, j3);
	free(j1); free(j2); free(j3);

	char *t1 = ft_strtrim("0101W0r1d110010", "01"), *t2 = ft_strtrim("W0r1d", "01"),
			*t3 = ft_strtrim("1110", "01"), *t4 = ft_strtrim("1110", ""),
			*t0a = ft_strtrim("UB", 0), *t5 = ft_strtrim("check+ ", " +");
	printf("\nstrtrim\nW0r1d=%s; W0r1d=%s; 0=%d; 1110=%s; UB=%s; check=%s\n",
		t1, t2, *t3, t4, t0a, t5);	free(t1); free(t2); free(t3); free(t4); free(t5);
		free(t0a);

   char **spfr;
	char *sp1 = "test just spaces", **sp1r = ft_split(sp1, ' '); spfr = sp1r;
	printf("\nsplit\n%s->[test][just][spaces]=", sp1); while(*sp1r) printf("[%s]", *sp1r++);
	sp1r = spfr; while(*sp1r){free(*sp1r); *sp1r++=NULL;}; free(spfr); sp1r = NULL;
	char *sp2 = "only two", **sp2r = ft_split(sp2, ' '); spfr = sp2r;
	printf("\n%s\t\t->[only][two]=", sp2); while(*sp2r) printf("[%s]", *sp2r++);
	sp2r = spfr; while(*sp2r) free(*sp2r++); free(spfr);
	char *sp3 = "ONE", **sp3r = ft_split(sp3, ' '); spfr = sp3r;
	printf("\n%s\t\t\t\t->[ONE]=",sp3); while(*sp3r)printf("[%s]",*sp3r++);
	sp3r = spfr; while(*sp3r) free(*sp3r++); free(spfr);
	char *sp4 = "...befr.n..aftr.", **sp4r = ft_split(sp4, '.'); spfr = sp4r;
	printf("\n%s->[befr][n][aftr]=", sp4); while(*sp4r) printf("[%s]", *sp4r++);
	sp4r = spfr; while(*sp4r) free(*sp4r++); free(spfr);
	char *sp5 = "delimeter is 0", **sp5r = ft_split(sp5, 0); spfr = sp5r;
	printf("\n%s\t->[delimeter is 0]", sp5); while(*sp5r) printf("[%s]", *sp5r++);
	sp5r = spfr; while(*sp5r) free(*sp5r++); free(spfr);
	char *sp0a = "..", **sp0ar = ft_split(sp0a, '.'); spfr = sp0ar;
	printf("\n%s\t\t\t\t->0=0",sp0a); while(*sp0ar) printf("[%s]", *sp0ar++);
	sp0ar = spfr; while(*sp0ar) free(*sp0ar++); free(spfr);
	char *sp0b = "", **sp0br = ft_split(sp0b, 'z'); spfr = sp0br;
	printf("\n%s\t\t\t\t->0=0", sp0b); while(*sp0br) printf("[%s]", *sp0br++);
	sp0br = spfr; while(*sp0br) free(*sp0br++); free(spfr);
//	char *sp9 = "!!f!a!i!l!.!", **sp9r = ft_split(sp9, '!');
//	printf("\n%s\t\t->", sp9); while(*sp9r) printf("[%s]", *sp9r++);


	char *itoa1=ft_itoa(21), *itoa2=ft_itoa(-42), *itoa3=ft_itoa(7), *itoa4 = ft_itoa(0),
		*itoa5 = ft_itoa(-3), *itoa6 = ft_itoa(INT_MIN), *itoa7 = ft_itoa(INT_MAX);
	printf("\n\nitoa\n21=%s; -42=%s; 7=%s; 0=%s; -3=%s; -2147483648=%s; 2147483647=%s\n",
		   itoa1, itoa2, itoa3, itoa4, itoa5, itoa6, itoa7);
	free(itoa1); free(itoa2); free(itoa3); free(itoa4); free(itoa5); free(itoa6); free(itoa7);

	printf("\nputchar\n");
	ft_putchar_fd('a', 1); printf("=a\n"); ft_putchar_fd('Z', 1); printf("=Z\n");

	printf("\nputstr\n");
	ft_putstr_fd("Hello,\n", 1); ft_putstr_fd("World!", 1);
	printf("\n^^^^^^ = Hello,\\nWorld!");

	printf("\nputendl\n");
	ft_putendl_fd("Here", 1); ft_putendl_fd("We", 1); ft_putendl_fd("Go!", 1);
	printf("^^^^ = Here\\nWe\\nGo!\n");

	printf("\nputnbr\n");
	ft_putnbr_fd(0, 1); ft_putnbr_fd(3, 1); ft_putnbr_fd(-7, 1); printf(" = 03-7\n");
	ft_putnbr_fd(21, 1); ft_putnbr_fd(-42, 1); printf(" = 21-42\n");
	ft_putnbr_fd(INT_MIN, 1); printf(" = %d\n", INT_MIN);
	ft_putnbr_fd(INT_MAX, 1); printf(" = %d\n", INT_MAX);

	printf("\nstrmapi\n");
	char *sm1 = ft_strmapi("Hello", mapicheck), *sm2 = ft_strmapi("cHEcK", mapicheck);
	printf("heLLO = %s; chECK = %s\n", sm1, sm2);
	free(sm1); free(sm2);
}

void check_5()
{
	char content[] = "Content!", *content0 = NULL;
	t_list *list = ft_lstnew(content), *list0 = ft_lstnew(content0);
	printf("\nlstnew\nContent! = %s; %p = %p\n", list->content, content0, list0->content);

	char content2[] = "Front";
	t_list *list2 = ft_lstnew(content2); ft_lstadd_front(&list, list2);
	printf("\nlstadd_front\nFront -> Content!	=\n%s -> %s\n",
		   list2->content, list2->next->content);

	char content3[] = "Back";
	t_list *list3 = ft_lstnew(content3); ft_lstadd_back(&list2, list3);
	printf("\nlstadd_back\nFront -> Content! -> Back	=\n%s -> %s -> %s\n",
		   list2->content, list2->next->content, list2->next->next->content);

	printf("\nft_lstsize\n3 = %d; 0 = %d; 1 = %d\n",
		   ft_lstsize(list2), ft_lstsize(0), ft_lstsize(list0));

	printf("\nft_lstlast\nBack = %s; (null) = %s\n",
		   ft_lstlast(list2)->content, ft_lstlast(list0)->content);

	ft_lstiter(list2, listiter);
	printf("\nft_lstiter\nFRONT -> CONTENT! -> BACK   =\n%s -> %s -> %s\n",
		   list2->content, list2->next->content, list2->next->next->content);

	t_list *listmap = ft_lstmap(list2, listmapper, listdel);
	printf("\nft_lstmap\nfront -> content! -> back   =\n%s -> %s -> %s\n",
		   listmap->content, listmap->next->content, listmap->next->next->content);

	list0->content = content; ft_lstdelone(list0, listdel);
	printf("\nft_lstdelone\nZontent! = %s\n", content);

	ft_lstclear(&list2, listdel); ft_lstclear(&listmap, listdel);
	printf("\nft_lstclear\n0x0 = %p, Zront = %s", list2, content2);
}

char mapicheck(unsigned index, char c){
	if (index > 1) return ((char)ft_toupper(c)); return ((char)ft_tolower(c));}

void listdel(void *s){if (s) *(char *)s = 'Z';}
void listiter(void *s){
	while (*(char *)s){*(char *)s = ft_toupper(*(char *)s); s++;};}
void *listmapper(void *s){char *start = s;
	while (*(char *)s){*(char *)s = ft_tolower(*(char *)s); s++;}
	return start;}

#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_toupper.c"
#include "ft_tolower.c"
#include "ft_strlen.c"
#include "ft_strlcpy.c"
#include "ft_strlcat.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strnstr.c"
#include "ft_strncmp.c"
#include "ft_atoi.c"
#include "ft_memset.c"
#include "ft_bzero.c"
#include "ft_memcpy.c"
#include "ft_memccpy.c"
#include "ft_memmove.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
#include "ft_calloc.c"
#include "ft_strdup.c"
#include "ft_substr.c"
#include "ft_strjoin.c"
#include "ft_strtrim.c"
#include "ft_split.c"
#include "ft_itoa.c"
#include "ft_putchar_fd.c"
#include "ft_putstr_fd.c"
#include "ft_putendl_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_strmapi.c"
#include "ft_lstnew.c"
#include "ft_lstadd_front.c"
#include "ft_lstadd_back.c"
#include "ft_lstdelone.c"
#include "ft_lstsize.c"
#include "ft_lstlast.c"
#include "ft_lstclear.c"
#include "ft_lstiter.c"
#include "ft_lstmap.c"
