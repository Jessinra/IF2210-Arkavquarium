#ifndef SAVE_H
#define SAVE_H

#include "Object.h"
#include "Aquarium.h"
#include "Guppy.h"
#include "Piranha.h"
#include "Pet.h"
#include "Siput.h"
#include "Food.h"
#include "Coin.h"
#include "LinkedList.h"

#include "Lib/oop.hpp"

using namespace std;

class Save {
    //method
    public:
        Save() {
            
        }

        // save and load
		void save(Aquarium aq) {
			
            cout << "1" << endl;
            if (!aq.get_list_guppy().isEmpty()) {
                for (int i=1; i<=aq.get_list_guppy().getNBelmt(); i++) {
                    guppy[i-1] = aq.get_list_guppy().get(i);
                }
            }
            cout << "2" << endl;
            nGuppy = aq.get_list_guppy().getNBelmt();
            if (!aq.get_list_piranha().isEmpty()) {
                for (int i=1; i<=aq.get_list_piranha().getNBelmt(); i++) {
                    piranha[i-1] = aq.get_list_piranha().get(i);
                }
            }
            cout << "3" << endl;
            nPiranha = aq.get_list_piranha().getNBelmt();
            if (!aq.get_list_siput().isEmpty()) {
                for (int i=1; i<=aq.get_list_siput().getNBelmt(); i++) {
                    siput[i-1] = aq.get_list_siput().get(i);
                }
            }
            cout << "4" << endl;
            nSiput = aq.get_list_siput().getNBelmt();
            if (!aq.get_list_food().isEmpty()) {
                for (int i=1; i<=aq.get_list_food().getNBelmt(); i++) {
                    food[i-1] = aq.get_list_food().get(i);
                }
            }
            nFood = aq.get_list_food().getNBelmt();
            if (!aq.get_list_coin().isEmpty()) {
                for (int i=1; i<=aq.get_list_coin().getNBelmt(); i++) {
                    coin[i-1] = aq.get_list_coin().get(i);
                }
            }
            nCoin = aq.get_list_coin().getNBelmt();
            FILE *file = fopen("saveFile", "wb");
			if (file != NULL) {
				fwrite(this, sizeof(Save), 1, file);
				fclose(file);
			}   
		}
		void load(Aquarium& aq) {
			FILE *file = fopen("saveFile", "rb");
			if (file != NULL) {
				fread(this, sizeof(Save), 1, file);
				fclose(file);
			}

            // guppy
            for (int i=0; i<nGuppy; i++) {
                aq.get_list_guppy().add(guppy[i]);
            }
            // piranha
            for (int i=0; i<nPiranha; i++) {
                aq.get_list_piranha().add(piranha[i]);
            }
            // siput
            for (int i=0; i<nSiput; i++) {
                aq.get_list_siput().add(siput[i]);
            }
            // food
            for (int i=0; i<nFood; i++) {
                aq.get_list_food().add(food[i]);
            }
            // coin
            for (int i=0; i<nCoin; i++) {
                aq.get_list_coin().add(coin[i]);
            }
		}

    //attr
	private:
        Guppy guppy[100];
        int nGuppy = 0;
		Piranha piranha[100];
        int nPiranha = 0;
		Siput siput[100];
        int nSiput = 0;
		Food food[200];
        int nFood = 0;
		Coin coin[200];
        int nCoin = 0;
			
};


#endif