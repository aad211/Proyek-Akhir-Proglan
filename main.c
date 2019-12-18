#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define lebar_layar 1080
#define tinggi_layar 720
#define phi 3.14159265358979323846

typedef struct {
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
}tombuol;

/*typedef struct {
	int player, map;
}tembak;*/

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	int atas, bawah, kiri, kanan, spasi;
	//tembak tembakan;
	int tombal[37];
	tombuol tombol;
}control;

typedef struct {
	int x, y;
	float sudut;
	SDL_Texture *texture;
} Entity;

control app;
int i;

void initSDL(void)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("PROYEK PROGLAN CUK!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, lebar_layar, tinggi_layar, windowFlags);
	
	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", lebar_layar, tinggi_layar, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	
	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
	
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void cleanup(void){
	SDL_DestroyRenderer(app.renderer);
	
	SDL_DestroyWindow(app.window);
	
	SDL_Quit();
}

SDL_Texture *loadTexture(char *filename){
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y, int sudut){
	//SDL Rect isinya -> x buat posisi x, y posisi y, w tinggi gambar, h lebar gambar
	SDL_Rect dest;
	
	dest.x = x;
	dest.y = y;
	//query texture buat ambil berapa tinggi dan lebar gambarnya
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	
	SDL_RenderCopyEx(app.renderer, texture, NULL, &dest, sudut, NULL, SDL_FLIP_NONE);
	//SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void dipencet(SDL_KeyboardEvent *pencetan){
	if (pencetan->repeat == 0){
		//printf("= %d\n", pencetan->keysym.scancode);
		//a itu adalah 4, dst
		if (pencetan->keysym.scancode == SDL_SCANCODE_UP){
			app.atas = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_DOWN){
			app.bawah = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_LEFT){
			app.kiri = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_RIGHT){
			app.kanan = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_W){
			app.tombol.w = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_A){
			app.tombol.a = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_S){
			app.tombol.s = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_D){
			app.tombol.d = 1;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_SPACE){
			app.spasi = 1;
			app.tombal[36]=1;
		}
		for(i=4; i<40; i++){
			if (pencetan->keysym.scancode == i){
				app.tombal[pencetan->keysym.scancode-4] = 1;
			}
		}
		/*for(i=0; i<36; i++){
			printf("tombal %d\n", app.tombal[i]);
		}*/
	}
}

void dilepas(SDL_KeyboardEvent *pencetan){
	if (pencetan->repeat == 0){
		if (pencetan->keysym.scancode == SDL_SCANCODE_UP){
			app.atas = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_DOWN){
			app.bawah = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_LEFT){
			app.kiri = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_RIGHT){
			app.kanan = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_W){
			app.tombol.w = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_A){
			app.tombol.a = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_S){
			app.tombol.s = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_D){
			app.tombol.d = 0;
		}
		if (pencetan->keysym.scancode == SDL_SCANCODE_SPACE){
			app.spasi = 0;
			app.tombal[36]=0;
		}
		for(i=4; i<40; i++){
			if (pencetan->keysym.scancode == i){
				app.tombal[pencetan->keysym.scancode-4] = 0;
			}
		}
	}
}

int main(int argc, char *argv[]){
	//ayok bantu mama buat jadi lebih pinter dengan cara meminjam buku, yuk pinjam buku sebanyak2nya untuk mendapat reward yang besar
	Entity player, map, mulai_tulisan, mulai_gambar, tulisan_pencetlanjut;
	
	memset(&app, 0, sizeof(control));
	memset(&player, 0, sizeof(Entity));
	
	initSDL();
	
	map.texture = loadTexture("img/mario.png");
	map.x = 0;
	map.y = tinggi_layar-720;
	map.sudut = 0;
	
	player.texture = loadTexture("img/emak_main.png");
	player.x = 10;
	player.y = tinggi_layar-97;
	player.sudut = 0;
	
	mulai_tulisan.texture = loadTexture("img/super_makmak_kecil.png");
	mulai_tulisan.x = 35;
	mulai_tulisan.y = tinggi_layar-565;
	mulai_tulisan.sudut = 0;
	
	mulai_gambar.texture = loadTexture("img/emaaakkk_kecil.png");
	mulai_gambar.x = -235;
	mulai_gambar.y = tinggi_layar-325;
	mulai_gambar.sudut = 0;
	
	/*tulisan_pencetlanjut.x = 100;
	tulisan_pencetlanjut.y = 300;
	mulai_gambar.texture = loadTexture("img/continue.png");*/
	
	atexit(cleanup);
	
	int lompat=0, x=0;
	//int awal=1, game=0, game1=0;
	int awal=1, game=0, game1=0;
	int r=170, g=134, b=95, a=255;
	
	char teks[100]={};
	int tek=0, flag=-1, count_flag=0;
	//teks = (char*)malloc(0*sizeof(char));
	
	while (1){
		//prepareScene();
		
		//nerima input
		SDL_Event pencetan;
		
		SDL_SetRenderDrawColor(app.renderer, r, g, b, a);
		SDL_RenderClear(app.renderer);
		
		if(awal){
			blit(mulai_tulisan.texture, mulai_tulisan.x, mulai_tulisan.y, mulai_tulisan.sudut);
			blit(mulai_gambar.texture, mulai_gambar.x, mulai_gambar.y, mulai_gambar.sudut);
			if(mulai_gambar.x<100){
				mulai_gambar.x+=3;
				if(mulai_gambar.x%5==0){
					mulai_gambar.y--;
				}
				mulai_gambar.sudut-=0.3;
			}
			else{
				while (SDL_PollEvent(&pencetan)){
					switch(pencetan.type){
						case SDL_KEYDOWN:
							awal=0;
							game=1;
							break;
					}
				}
			}
		}
		
		while (SDL_PollEvent(&pencetan))
		{
			switch (pencetan.type)
			{
				case SDL_QUIT:
					exit(0);
					break;
				
				//case SDL_TEXTINPUT:
                    /* Add new text onto the end of our text */
                    //strcat(teks, pencetan.text.text);
                    //break;
				
				
				
				//kalo lagi dipencet
				case SDL_KEYDOWN:
					dipencet(&pencetan.key);
					//printf("player 1 -> x = %d, y = %d.....player 2 -> x = %d, y = %d\n", player.x, player.y, map.x, map.y);
					break;
				
				//kalo lagi gak dipencet
				case SDL_KEYUP:
					dilepas(&pencetan.key);
					break;
	
				default:
					break;
			}
		}
		
		//main game
		if(game){
			if(app.spasi){
				lompat=1;
			}
			if(lompat){
				int skala = 100, sudut=45;
				int lama_waktu=25; //dalam satuan x
				if(x<=lama_waktu){
					//printf("woy %f\n", skala*(cos(((2*x*phi)/skala)+phi)+1)/2);
					player.y = tinggi_layar-97-(skala*(cos((2*x*phi/lama_waktu)+phi)+1)/2);
					player.sudut = (sudut*cos((2*x*phi/lama_waktu)+(phi/2))/2);
					x++;
				}
				else{
					lompat=0;
					x=0;
				}
			}
			
			//batas maju player adalah batas karakter maju dan gantian sama layarnya
			int batas_maju_player = 100;
			
			if(app.tombol.a){
				if(player.x>10){
					player.x-=5;
				}
				else{
					if(map.x<0){
						map.x+=5;
					}
					else{
						map.x=0;
					}
				}
			}
			if(app.tombol.d){
				if(player.x<batas_maju_player){
					player.x+=5;
				}
				else{
					if(game1){
						
					}
					else{
						if(map.x>1280-3840-batas_maju_player){
							map.x-=5;
						}
						else{
							map.x=1280-3840-batas_maju_player;
							if(player.x<lebar_layar-48){
								player.x+=5;
							}
							else{
								player.x=lebar_layar-48;
							}
						}
					}
				}
			}
			
			//scene 2
			char tambol[37]={"abcdefghijklmnopqrstuvwxyz1234567890 "};
			if(game1){
				SDL_DestroyTexture(map.texture);
				SDL_DestroyTexture(player.texture);
				if(flag==-1){
					for(i=0; i<37; i++){
						if(app.tombal[i]){
							teks[tek]=tambol[i];
							tek++;
							a-=15;
							//teks = (char*)realloc(teks, tek*sizeof(char));
							flag=i;
							//strcat(teks, tambol[i]);
							printf("%d %s\n", a, teks);
						}
					}
				}
				else{
					if(app.tombal[flag]==0){
						flag=-1;
					}
					/*if(count_flag<5){
						count_flag++;
					}
					else{
						count_flag=0;
						flag=1;
					}*/
				}
				//printf("%s", teks);
				//strcat(teks, );
				//SDL_StartTextInput();
				//r=0; g=0; b=0; a=0;
			}
			//scene 1
			else{
				if(app.tombol.w){
					if(map.x==1280-3840-batas_maju_player){
						if(player.x>=890&&player.x<=1000){
							game1=1;
						}
					}
				}
				
				blit(map.texture, map.x, map.y, map.sudut);
				blit(player.texture, player.x, player.y, player.sudut);
				
				r=170; g=255; b=100; a=255;
			}
		}
		
		SDL_RenderPresent(app.renderer);
		
		SDL_Delay(16);
	}

	return 0;
}
