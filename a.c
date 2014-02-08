		#include<stdio.h>
		#include<stdlib.h>
		#include<string.h>
		struct book
		{
			int id,current,stock;
			char name[20],auth[20];
		}*ptr;
		struct issue
		{
			int stid;
			char book_name[30];
		}*ptr1;
	void add();
	void display1();
	void search();
	void iss();	
	void unissue();
	void display2();
			FILE *p,*q,*r,*s;
			
		
		void main()
	 	{
	
			ptr1=malloc(sizeof(struct issue));
			ptr=malloc(sizeof(struct book));
			int option;
			printf("1:\nadd\n2:display stock detail\n3:search\n4:issue\n5:to unissue\n6:to display issue detail");
			printf("enter u r option");
			scanf("%d",&option);
			switch(option)
			{	
				case 1:
					add();
					break;
				case 2:
					display1();
					break;
				case 3:
					search();
					break;
				case 4:
					iss();
					break;
				case 5:
					unissue();
					break;
				case 6:
					display2();
					break;
				default :
				
					break;
			}
		}
		void add()
		{
		
			int z=1,k;
			char s[100];
			int id1;
			
			printf("Enter no:");
			scanf("%d",&id1);
			p=fopen("aaa","a+");
			q=fopen("bbb","w");

			while(1)	
			{
				fread(ptr,sizeof(struct book),1,p);
				if(feof(p))
				break;
					if( (ptr->id)== id1)
					{
						(ptr->stock)=(ptr->stock)+1;
						fwrite(ptr,sizeof(struct book),1,q);
						z=2;
					}
					else
					{
						fwrite(ptr,sizeof(struct book),1,q);
					}
			}
					if(z!=2)
					{	ptr->current=0;
						(ptr->id)=id1;
						printf("Enter Book Name:");
						scanf("%s",(ptr->name));
						printf("Enter Author Name:");
						scanf("%s",(ptr->auth));
						printf("Enter Quantity:");
						scanf("%d",&(ptr->stock));
						fwrite(ptr,sizeof(struct book),1,q);
					}
				fclose(p);
				fclose(q);
				rename("bbb","aaa");
	}
			void search()
			{
				char s[100];
				printf("enter the name to search\n");
				scanf("%s",s);
				p=fopen("aaa","r");
				int flag;
	
			while(1)
			{
					fread(ptr,sizeof(struct book),1,p);
						if( feof(p) )
						break;
					if( !strcmp( s, (ptr->name) ))
					{
						flag=1;
						break;
					}
			}
					if(flag==1)
					{	
						printf("%d\t%s\t%s\t%d\t%d",ptr->id,ptr->name,ptr->auth,ptr->stock,ptr->current);
						int q=(ptr->stock)-(ptr->current);
						printf("\n%d books are available\n",q);
					}
					else
					{
						printf("book not available\n");
					}	
	
				fclose(p);
			}
			void iss()
			{   
				char b[100];
				int stdid,check;
				printf("enter the student  id:");
				scanf("%d",&stdid);
				printf("enter the book name to issue");
				scanf("%s",b);
				r=fopen("ccc","a+");
				p=fopen("aaa","r");
				q=fopen("bbb","w");
				while(1)
				{
						
				fread(ptr,sizeof(struct book),1,p);
				    if( feof(p) )
					break;
					    if((ptr->current)<(ptr->stock))
						{
							if( !strcmp(b,ptr->name) )
							{
								(ptr->current)=(ptr->current)+1;
								fwrite(ptr,sizeof(struct book),1,q);
								check=1;
							}
							else
							{	
								fwrite(ptr,sizeof(struct book),1,q);
							
							}
						}
					else
					{
						printf("\n all the books issued......");
					}	
				}
				if(check==1)
				{
					printf("issued succesfully\n");		
                                          strcpy((ptr1->book_name),b);
						(ptr1->stid)=stdid;
                                                  fwrite(ptr1,sizeof(struct issue),1,r);
                                        
                    		}
				else
				{
				printf("not issued\n");
				}
				fclose(p);
				fclose(q);
				fclose(r);
				rename("bbb","aaa");
				}
			void unissue()
			{
				char b[100];
                                int stdid,check;
                                printf("enter the student  id:");
                                scanf("%d",&stdid);
                                printf("enter the book name to unissue");
                                scanf("%s",b);
				s=fopen("ddd","w");
				r=fopen("ccc","r");
                                p=fopen("aaa","r");
                                q=fopen("bbb","w");
                                while(1)
                                {

                                  fread(ptr,sizeof(struct book),1,p);
                                   if( feof(p) )
                                        	break;
                                                
                                                
							if( !strcmp(b,ptr->name) )
                                                {
							
                                                        (ptr->current)=(ptr->current)-1;
                                                        fwrite(ptr,sizeof(struct book),1,q);
                                                        check=1;
                                                }
                                                else
                                                {
                                                        fwrite(ptr,sizeof(struct book),1,q);

                                                } 
				}
                   
		
                                if(check==1)
                                {
                                        printf("unissued succesfully\n");
					while(1)
                                	{

                                        fread(ptr1,sizeof(struct issue),1,r);
                                        if( feof(p) )
                                        break;
					if( (ptr1->stid) !=stdid) 
					{
					fwrite(ptr1,sizeof(struct issue),1,s);
					}

                                }
			}
                                else
                                {
                                printf("not unissued\n");
                                }
				fclose(p);
				fclose(q);
				fclose(r);
				fclose(s);
				rename("ddd","ccc");
				rename("bbb","aaa");
}
                                
			

				
			void display1()
			{
				p=fopen("aaa","r");
				while(1)
				{
					fread(ptr,sizeof(struct book),1,p);
					if( feof(p) )
					break;
					printf("\n%d\t%s\t%s\t%d\t%d\t\n",ptr->id,ptr->name,ptr->auth,ptr->stock,ptr->current);
		
				}
				fclose(p);
			}
			void display2()
			{
				r=fopen("ccc","r");
				while(1)
				{
					fread(ptr1,sizeof(struct issue),1,r);
					if(feof(r))
					break;
					printf("\n%d\t%s",ptr1->stid,ptr1->book_name);
				}
			fclose(r);
			}
		
