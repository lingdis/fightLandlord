'''
Created on 2013-8-10

@author: Lingdy
'''

class game(object):
    
    def __init__(self, cards, players): #15 for little joker and 16 for big joker  
        if(cards == None):
            self.cards = [];
            for i in range(1,14):
                for j in range(0,4):
                    self.cards.append(i);
            self.cards.append(15);
            self.cards.append(16);
        else:
            self.cards = cards;
        
        if(players == None):
            self.players = None;
            assert False;
        else:
            self.players = players;
        
        self.last_player = None;
        self.current_player = None;
        self.current_card = None;
        
    def shuffle(self):
        
        return;
    
    def deal(self):
        return;
    
    def log_process(self):
        return;
    
    def game_play(self):
        
        self.shuffle();
        self.deal();
        
        self.landlord = None;
        
        self.decide_lord();
        
        self.game_end = False;
        cards = None;
        
        while(not self.game_end):
            if(self.current_player == self.last_player):
                cards = self.players[self.current_player].free_play();
            else:
                cards = self.players[self.current_player].play();
            
            if(self.players[self.current_player].is_win()):
                self.game_end = True;
                self.winner = self.current_player;
                self.log_process();
                break;
             
            if(cards == None):
                continue;
            else:
                self.current_card = cards;
                self.last_player();
                self.last_player = self.current_player;
                self.current_player = self.next_player();
                

    def decide_lord(self):
        return;
    
    def next_player(self):
        return (self.current_player+1)%len(self.players);
    

class player(object):
    
    def free_play(self):
        return;
        
    def play(self):
        return;
    
    
        