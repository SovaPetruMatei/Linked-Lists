#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;

} nod, *adr;

void afisare(adr head)
{
    adr p=head;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}


void afisare_inversa(adr p)
{

    if(p==NULL)
        return;

    afisare_inversa(p->next);
    printf("%d ",p->info);
}

adr cauta(adr p,int x)
{
    while(p!=NULL && p->info!=x)
        p=p->next;

    return p;

}

adr insereaza(adr head,int x)
{
    adr t=(adr)malloc(sizeof(nod));
    t->info=x;
    t->next=NULL;

    if(head==NULL)
        return t;

    t->next=head;
    head=t;
    return head;
}

adr insereaza_sfarsit(adr head,int x)
{
    adr t=(adr)malloc(sizeof(nod));
    t->info=x;
    t->next=NULL;

    if(head==NULL)
        return t;

    adr p=head;
    while(p->next!=NULL)
        p=p->next;

    p->next=t;

    return head;
}

adr insereaza_dupa_x(adr head,int x,int d)
{
    adr t=(adr)malloc(sizeof(nod));
    t->info=d;
    t->next=NULL;

    adr p=head;
    while(p!=NULL && p->info!=x)
        p=p->next;

    if(p==NULL)
    {
        free(t);
        return head;
    }

    t->next=p->next;
    p->next=t;
    return head;

}

adr insereaza_ordonat(adr head,int x)
{
    adr t=(adr)malloc(sizeof(nod));
    t->info=x;
    t->next=NULL;

    if(head==NULL || t->info < head->info)
    {
        t->next=head;
        head=t;
        return head;
    }

    adr prev=head;
    adr curr=head->next;

    while(curr!=NULL && x>curr->info)
    {
        prev=curr;
        curr=curr->next;
    }

    t->next=prev->next;
    prev->next=t;

    return head;

}

adr elimina(adr head)
{
    if(head==NULL)
        return NULL;

    adr t=head;
    head=head->next;
    free(t);

    return head;

}

adr elimina_x(adr head,int x)
{
    if(head==NULL)
        return NULL;


    adr t=head;
    adr prev=NULL;

    if(head->info==x)
    {

        head=head->next;
        free(t);
        return head;
    }

    while(t!=NULL && t->info!=x)
    {
        prev=t;
        t=t->next;
    }

    if(t==NULL)
        return head;


    prev->next=t->next;
    free(t);

    return head;


}

int main()
{
    adr head=NULL,t;
    int x;
    while(scanf("%d",&x)==1)
    {
        head=insereaza(head,x);
    }

    rewind(stdin);
    scanf("%d",&x);

    head=insereaza_ordonat(head,x);

    afisare(head);



    return 0;

}
