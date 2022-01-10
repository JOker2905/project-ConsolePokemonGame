#include <random>
#include "Battle.h"

Battle::Battle() {

}
Battle::~Battle() {

}

void Battle::battle(Trainer& trainer, Trainer& enemyTrainer) {
    bool playerturn= true;
    int choice=0;

    int counter=0;
    int activepokemon=0;
    int activeenemypokemon=0;
    int combatRoll;
    int damage=0;
    int gainexp=10;
    bool trainerDefeated= false;
    bool activepokemondefeated= false;
    bool enemytrainerDefeated= false;
    bool battleresult= false;

    while (!trainerDefeated&&!enemytrainerDefeated){
        if (playerturn&&!trainerDefeated){
            if (trainer.pokemon(activepokemon).getExp()>=trainer.pokemon(activepokemon).getExpNext()){
                cout<<"YOU CAN EVOLVE YOUR POKEMON"<<"\n";
            }
            if (activepokemondefeated){
                cout<<"YOU NEED TO CHOOSE POKEMON"<<"\n\n";
                for (int i = 1; i < 7; ++i) {
                    if (trainer.pokemon(i-1).ispokemonalive()){
                        cout<<i<<"."<<trainer.pokemon(i-1).getName()<<"  HP:"<<trainer.pokemon(i-1).getHP()<<"  Strength:"<<trainer.pokemon(i-1).getStrength()<<"\n";
                    } else{
                        cout<<i<<"."<<trainer.pokemon(i-1).getName()<<"  HP:"<<trainer.pokemon(i-1).getHP()<<"  Strength:"<<trainer.pokemon(i-1).getStrength()<<"  (DEFEATED)"<<"\n";
                    }
                }
                cout<<"\n";
                cout<<"Choice: ";
                cin>>choice;
                while (cin.fail()||choice>7||choice<1){
                    cout<<"Wrong input!"<<"\n";
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cout<<"Choice: ";
                    cin>>choice;
                }
                while (!trainer.pokemon(choice-1).ispokemonalive()){
                    cout<<"THIS POKEMON IS DEFEATED"<<"\n";
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    cout<<"Choice: ";
                    cin>>choice;
                }
                activepokemon=choice-1;
                activepokemondefeated= false;
            }
            cout<<"**YOUR TURN**"<<"\n\n";
            cout<<"**BATTLE MENU**"<<"\n\n";
            cout<<"Active pokemon:"<<trainer.pokemon(activepokemon).getName()<<"  HP:"<<trainer.pokemon(activepokemon).getHP()<<"/"<<trainer.pokemon(activepokemon).getHPmax()<<"  Strength:"<<trainer.pokemon(activepokemon).getStrength()<<"   Typ:"<<trainer.pokemon(activepokemon).getPokemontype()<<"\n\n";
            cout<<"Enemy pokemon:"<<enemyTrainer.pokemon(activeenemypokemon).getName()<<"  HP:"<<enemyTrainer.pokemon(activeenemypokemon).getHP()<<"/"<<enemyTrainer.pokemon(activeenemypokemon).getHPmax()<<"  Strength:"<<enemyTrainer.pokemon(activeenemypokemon).getStrength()<<"   Typ:"<<enemyTrainer.pokemon(activeenemypokemon).getPokemontype()<<"\n\n";
            cout<<"1: Attack"<<"\n";
            cout<<"2: Spiecial ability"<<"\n";
            cout<<"3: Change pokemon"<<"\n";
            cout<<"4: Evolve pokemon"<<"\n";
            cout<<"\n";

            cout<<"Choice: ";
            cin>>choice;

            while (cin.fail()||choice>4||choice<1){
                cout<<"Wrong input!(1-4)"<<"\n";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout<<"**BATTLe MENU**"<<"\n\n";
                cout<<"1: Attack"<<"\n";
                cout<<"2: Spiecial ability"<<"\n";
                cout<<"3: Change pokemon"<<"\n";
                cout<<"4: Evolve pokemon"<<"\n";

                cout<<"Choice: ";
                cin>>choice;
            }
            switch (choice) {
                case 1://ATTACK
                    combatRoll=rand()%enemyTrainer.pokemon(activeenemypokemon).getDexterity()+1;
                    if (trainer.pokemon(activepokemon).getStrength()>combatRoll){
                        cout<<"HIT!"<<"\n\n";
                        if (trainer.pokemon(activepokemon).getPokemontype()=="woda"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                        }
                        if (trainer.pokemon(activepokemon).getPokemontype()=="ziemia"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                        }
                        if (trainer.pokemon(activepokemon).getPokemontype()=="powietrze"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                        }
                        if (trainer.pokemon(activepokemon).getPokemontype()=="ogien"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                        }
                        if (trainer.pokemon(activepokemon).getPokemontype()=="lod"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                        }
                        if (trainer.pokemon(activepokemon).getPokemontype()=="stal"){
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="woda"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ziemia"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="powietrze"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="ogien"){
                                damage=trainer.pokemon(activepokemon).getStrength()+3;
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="lod"){
                                damage=trainer.pokemon(activepokemon).getStrength();
                            }
                            if (enemyTrainer.pokemon(activeenemypokemon).getPokemontype()=="stal"){
                                damage=trainer.pokemon(activepokemon).getStrength()-3;
                            }
                        }
                        enemyTrainer.pokemon(activeenemypokemon).takeDamage(damage);
                        cout<<"Damage: "<<damage<<"!"<<"\n\n";

                        counter++;
                        if (!enemyTrainer.pokemon(activeenemypokemon).ispokemonalive()){
                            cout<<"ENEMY POKEMON DEAFEATED!"<<"\n\n";
                            trainer.pokemon(activepokemon).gainExp(gainexp);
                            cout<<"EXP GAINED: "<<gainexp<<"\n";
                            cout<<"\n";
                            if (activeenemypokemon<4){
                                activeenemypokemon++;
                                }
                        }
                    } else{
                        cout<<"MISSED!"<<"\n\n";
                    }
                    playerturn= false;
                    break;
                case 2://SPECIAL ABILITY
                    if (counter==3) {
                        cout << "YOU USE SPIECIAL ABILITY" << "\n";
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="unik"){
                            trainer.pokemon(activepokemon).ImproveDexterity(2);
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="chlorofil"){
                            enemyTrainer.pokemon(activeenemypokemon).takeDamage(10);
                            if (!enemyTrainer.pokemon(activeenemypokemon).ispokemonalive()){
                                cout<<"ENEMY POKEMON DEAFEATED!"<<"\n\n";
                                trainer.pokemon(activepokemon).gainExp(gainexp);
                                cout<<"EXP GAINED: "<<gainexp<<"\n";
                                if (activeenemypokemon<4){
                                    activeenemypokemon++;
                                }
                            }
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="zbierakwody"){
                                enemyTrainer.pokemon(activeenemypokemon).takeDamage(8);
                            if (!enemyTrainer.pokemon(activeenemypokemon).ispokemonalive()){
                                cout<<"ENEMY POKEMON DEAFEATED!"<<"\n\n";
                                trainer.pokemon(activepokemon).gainExp(gainexp);
                                cout<<"EXP GAINED: "<<gainexp<<"\n";
                                if (activeenemypokemon<4){
                                    activeenemypokemon++;
                                }
                            }
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="ucieczka"){
                                trainer.pokemon(activepokemon).ImproveDexterity(3);
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="pospiech"){
                                trainer.pokemon(activepokemon).ImproveDexterity(5);
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="snajper"){
                                trainer.pokemon(activepokemon).ImproveStrength(5);
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="silaslonca"){
                                enemyTrainer.pokemon(activepokemon).takeDamage(12);
                            if (!enemyTrainer.pokemon(activeenemypokemon).ispokemonalive()){
                                cout<<"ENEMY POKEMON DEAFEATED!"<<"\n\n";
                                trainer.pokemon(activepokemon).gainExp(gainexp);
                                cout<<"EXP GAINED: "<<gainexp<<"\n";
                                if (activeenemypokemon<4){
                                    activeenemypokemon++;
                                }
                            }
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="uziemienie"){
                                enemyTrainer.pokemon(activeenemypokemon).takeDamage(15);
                            if (!enemyTrainer.pokemon(activeenemypokemon).ispokemonalive()){
                                cout<<"ENEMY POKEMON DEAFEATED!"<<"\n\n";
                                trainer.pokemon(activepokemon).gainExp(gainexp);
                                cout<<"EXP GAINED: "<<gainexp<<"\n";
                                if (activeenemypokemon<4){
                                    activeenemypokemon++;
                                }
                            }
                        }
                        if (trainer.pokemon(activepokemon).getSpiecialPowerName()=="odpornosc"){
                                trainer.pokemon(activepokemon).ImproveHp(10);
                        }
                        playerturn= false;
                    } else{
                            cout<<"ABILITY IS NOT READY"<<"\n";
                    }
                    break;
                case 3://CHANGE POKEMON
                    cout<<"CHOOSE POKEMON TO CHANGE"<<"\n\n";
                    for (int i = 1; i < 7; ++i) {
                        if (trainer.pokemon(i-1).ispokemonalive()){
                            cout<<i<<"."<<trainer.pokemon(i-1).getName()<<"  HP:"<<trainer.pokemon(i-1).getHP()<<"  Strength:"<<trainer.pokemon(i-1).getStrength()<<"\n";
                        } else{
                            cout<<i<<"."<<trainer.pokemon(i-1).getName()<<"  HP:"<<trainer.pokemon(i-1).getHP()<<"  Strength:"<<trainer.pokemon(i-1).getStrength()<<"  (DEFEATED)"<<"\n";
                        }
                    }
                    cout<<"Choice: ";
                    cin>>choice;
                    while (cin.fail()||choice>7||choice<1){
                        cout<<"Wrong input!"<<"\n";
                        cin.clear();
                        cin.ignore(INT_MAX,'\n');
                        cout<<"Choice: ";
                        cin>>choice;
                    }
                    while (!trainer.pokemon(choice-1).ispokemonalive()){
                        cout<<"THIS POKEMON IS DEFEATED"<<"\n";
                        cin.clear();
                        cin.ignore(INT_MAX,'\n');
                        cout<<"Choice: ";
                        cin>>choice;
                    }
                    activepokemon=choice-1;
                    playerturn= false;
                    counter=0;
                    break;
                case 4://EVOLVE POKEMON
                    if (trainer.pokemon(activepokemon).getExp()>=trainer.pokemon(activepokemon).getExpNext()) {
                        trainer.pokemon(activepokemon).evolve();
                        for (int i = 0; i < 2; ++i) {
                            cout << "CHOOSE STATS TO IMPROVE" << "\n";
                            cout << "1.HP" << "\n";
                            cout << "2.Strength" << "\n";
                            cout << "3.Dexterity" << "\n";
                            cout << "\n";
                            cout << "Choice: ";
                            cin >> choice;
                            while (cin.fail() || choice > 3 || choice < 1) {
                                cout << "Wrong input!" << "\n";
                                cin.clear();
                                cin.ignore(INT_MAX,'\n');
                                cout << "Choice: ";
                                cin >> choice;
                            }
                            switch (choice) {
                                case 1:
                                    trainer.pokemon(activepokemon).ImproveHp(5);
                                    break;
                                case 2:
                                    trainer.pokemon(activepokemon).ImproveStrength(5);
                                    break;
                                case 3:
                                    trainer.pokemon(activepokemon).ImproveDexterity(2);
                                    break;
                                default:
                                    break;
                            }
                        }
                        playerturn = false;
                    } else{
                        cout<<"NOT ENOUGH XP"<<"\n";
                        cout<<"YOUR POKEMON NEED TO DEFEND 3 POKEMONS"<<"\n\n";
                    }
                    break;
                default:
                    break;
            }
        } else if (!playerturn&&!trainerDefeated&&!enemytrainerDefeated){
            cout<<"**ENEMY TURN**"<<"\n";

            cout<<"Enemy:"<<enemyTrainer.pokemon(activeenemypokemon).getName()<<"  HP:"<<enemyTrainer.pokemon(activeenemypokemon).getHP()<<"/"<<enemyTrainer.pokemon(activeenemypokemon).getHPmax()<<"  Strength:"<<enemyTrainer.pokemon(activeenemypokemon).getStrength()<<"\n\n";

            combatRoll=rand()%trainer.pokemon(activepokemon).getDexterity()+1;
            if (enemyTrainer.pokemon(activeenemypokemon).getStrength()>combatRoll){
                cout<<"HIT! "<<"\n\n";
                damage=enemyTrainer.pokemon(activeenemypokemon).getStrength();
                trainer.pokemon(activepokemon).takeDamage(damage);
                cout<<"Damage: "<<damage<<"!"<<"\n";
                if (!trainer.pokemon(activepokemon).ispokemonalive()) {
                    cout << "YOUR POKEMON IS DEFEATED!" << "\n\n";
                    activepokemondefeated = true;
                }
            }else{  //MISS
                cout<<"MISSED!"<<"\n\n";
            }
            playerturn= true;
        }

        int allpokemondefeated=0;
        for (int i = 0; i < 6; ++i) {
            if (!trainer.pokemon(i).ispokemonalive())
                allpokemondefeated++;
        }
        int counter1=0;
        for (int i = 0; i <4 ; ++i) {
            if (!enemyTrainer.pokemon(i).ispokemonalive())
                counter1++;
        }
        if (allpokemondefeated == 6){
            trainerDefeated= true;
            battleresult= false;
        } else if (counter1==4){
            enemytrainerDefeated= true;
            battleresult= true;
        }
    }
    if (battleresult) {
        for (int i = 0; i < 6; ++i) {
            trainer.pokemon(i).restorehp();
        }
    }
}