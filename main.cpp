#include <allegro.h>
#include <alpng.h>
#include <alfont.h>
#include <gstream.h>
#include <math.h>

void init();
void deinit();
float vr(float w[],int m,float x);

int main() {
	init();

float v[20],x,y,ant,zum=10;
int n,i;
int pol=0;
float a,b;

//gstream gs;
//gs.set_bitmap(screen);
//gs.set_color(173);
//gs.goto_xy(10,20);
//gs.set_max_input_length(20);
//gs<<flush;
//gs<<"saulo";
//gs>>v[0];
//gs.goto_xy(10,30);


//putpixel(screen,vr(v,n,x)+200,y+200,200);   

 cout<<" Grau =";
		cin>>n;
 cout<<"intevalo (a,b) a<b: \n"	;	
 cout<<"\n a=";
 cin>>a;
 cout<<"\n b=";
 cin>>b;

     cout<<"\n emtre com o zum:";
     cout<<"\n ZUM=";
     cin>>zum;
     cout<<"\n";

	 cout<<"Polinomio completo na ordem decresente!";
	 cout<<"\n\n";

	for(i=n;i>=0;i--)
	 {cout<<"p["<<i<<"]=";
		cin>>v[i];}
		 
         
         ant=vr(v,n,a);

    
       hline(screen,0,240,640,makecol(0,200,0)); //  x1,y,x2  
       vline(screen,320,0,480,makecol(0,200,0)); //   x,y1,y2 

	  for(x=a;x<=b;x=x+0.0001)//intevalo
	  {      
	  if(ant*vr(v,n,x)<0){
        cout<<x<<"\n"; pol=1; 
            }
	  ant=vr(v,n,x);

      y=ant;
      if(y==0)
         cout<<"passa pela origem";
     putpixel(screen,(int)(x*zum)+320,(int)(-y*zum)+240,200);
     
    // putpixel(screen,(int)(x*zum)+320,(int)(-tan(y)*zum)+240,makecol(203,32,200));
     //putpixel(screen,(int)(x*zum)+320,(int)(-cos(y)*zum)+240,makecol(255,0,0));
     //putpixel(screen,(int)(x*zum)+320,(int)(-sin(y)*zum)+240,makecol(0,56,120)); 
     }
    
   if(pol==0)
       cout<<"nao posui raises";    

	while (!key[KEY_ESC]) {
        
		/* put your code here */
	// textprintf_ex(screen,font,100,100,makecol(0,255,0),-1,"x: %d ",x);
    	
	}

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	alpng_init();
	alfont_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	alfont_exit(); 
	/* add other deinitializations here */
}


float vr(float w[],int m,float x)
 { float z;

  int i;

		z=w[0];

		for(i=m;i>0;i--){
           z=z+w[i]*pow(x,i);}

 return z;
 }

// ok=false;
//    if(p(a)*p(b)<0)
//      {ok=true;
//      while(|a-b|>0.001) 
//       {x=(bp(a)-ap(b)) / ( p(a)-p(b)); 
//          if (p(x)*p(a)<0) 
//            b=x ;
//         else 
//            a=x;
//       }
//    }if (ok=true)
//       imprima (a+b)/2;
//    else 
//       imprima “Não tem raiz neste intervalo”







