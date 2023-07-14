#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME mifunc


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  const vector<Dir> dirs = {Up,Down,Left,Right};

  typedef vector<vector<CellType>> Tauler;

  typedef vector<vector<int>> Dist;

  typedef vector<vector<bool>> Vist;

  //typedef vector<vector<Pos>> prev;

  int bfs_menjar(Pos pos, Pos& pos_obj, vector<vector<Pos>>& prev) { //dist minima a menjar
    queue<Pos> q; //coord
    Dist d(board_rows(),vector<int>(board_cols(),-1)); //dist a -1
    q.push(pos);
    d[pos.i][pos.j] = 0; //comensament
    while(not q.empty()) {
      Pos p = q.front();
      q.pop();
      for(auto di : dirs) {
        Pos n_pos = p + di;
        if (pos_ok(n_pos) and cell(n_pos.i,n_pos.j).type != Waste and d[n_pos.i][n_pos.j] == -1) {
          q.push(n_pos);
          d[n_pos.i][n_pos.j] = d[p.i][p.j] +1;
          prev[n_pos.i][n_pos.j] = p;
          if(cell(n_pos.i,n_pos.j).food) {
            pos_obj = n_pos;
            return d[n_pos.i][n_pos.j];
          } 
        }
      }
    }
    return -1;
  }


  int bfs_zombie(Pos pos, Pos& pos_obj, vector<vector<Pos>>& prev) { //dist minima a zombie
    queue<Pos> q; //coord
    Dist d(board_rows(),vector<int>(board_cols(),-1)); //dist a -1
    q.push(pos);
    d[pos.i][pos.j] = 0; //comensament
    while(not q.empty()) {
      Pos p = q.front();
      q.pop();
      for(auto di : dirs) {
        Pos n_pos = p + di;
        if (pos_ok(n_pos) and cell(n_pos.i,n_pos.j).type != Waste and d[n_pos.i][n_pos.j] == -1) {
          q.push(n_pos);
          d[n_pos.i][n_pos.j] = d[p.i][p.j] +1;
          int id_in_cell = cell(n_pos.i,n_pos.j).id;
          prev[n_pos.i][n_pos.j] = p;
          if (id_in_cell != -1 and unit(id_in_cell).type == Zombie) {
            pos_obj = n_pos;
            return d[n_pos.i][n_pos.j];
          }
        }
      }
    }
    return -1;
  }
  

  int bfs_dummy(Pos pos, Pos& pos_obj, vector<vector<Pos>>& prev) { //dist minima a dummy
    queue<Pos> q; //coord
    q.push(pos);
    Dist d(board_rows(),vector<int>(board_cols(),-1)); //dist a -1
    d[pos.i][pos.j] = 0; //comensament
    while(not q.empty()) {
      Pos p = q.front();
      q.pop();
      for(auto di : dirs) {
        Pos n_pos = p + di;
        if (pos_ok(n_pos) and cell(n_pos.i,n_pos.j).type != Waste and d[n_pos.i][n_pos.j] == -1) {
          q.push(n_pos);
          d[n_pos.i][n_pos.j] = d[p.i][p.j] + 1;
          prev[n_pos.i][n_pos.j] = p;
          int id_in_cell = cell(n_pos.i,n_pos.j).id;
          if (id_in_cell != -1 and unit(id_in_cell).type == Alive and unit(id_in_cell).player!=me()) {
            pos_obj = n_pos;
            return d[n_pos.i][n_pos.j];
          } 
        }
      }
    }
    return -1;
  }

  int bfs_dead(Pos pos, Pos& pos_obj, vector<vector<Pos>>& prev,int& rfz) { //dist minima a dead
    queue<Pos> q; //coord
    q.push(pos);
    Dist d(board_rows(),vector<int>(board_cols(),-1)); //dist a -1
    d[pos.i][pos.j] = 0; //comensament
    while(not q.empty()) {
      Pos p = q.front();
      q.pop();
      for(auto di : dirs) {
        Pos n_pos = p + di;
        if (pos_ok(n_pos) and cell(n_pos.i,n_pos.j).type != Waste and d[n_pos.i][n_pos.j] == -1) {
          q.push(n_pos);
          d[n_pos.i][n_pos.j] = d[p.i][p.j] + 1;
          prev[n_pos.i][n_pos.j] = p;
          int id_in_cell = cell(n_pos.i,n_pos.j).id;
          if (id_in_cell != -1 and unit(id_in_cell).type == Dead) {
            pos_obj = n_pos;
            rfz = unit(id_in_cell).rounds_for_zombie;
            return d[n_pos.i][n_pos.j];
          } 
        }
      }
    }
    return -1;
  }


  Dir funcio(Pos act, Pos pos_obj, vector<vector<Pos>>& prev) {
    Pos aux_previ;
    while((pos_obj) != act) {
      aux_previ = pos_obj;
      pos_obj = prev[pos_obj.i][pos_obj.j];
    }

    if(act+Up == aux_previ) return Up;
    else if(act+Down == aux_previ) return Down;
    else if(act+Left == aux_previ) return Left;
    else return Right;
  }


  bool hay_zombie_diago(Pos LD, Pos UL, Pos DR, Pos RU, Pos DLD, Pos UUL, Pos DDR, Pos URU, Pos z){
    if(LD==z or UL==z or DR==z or RU==z or DLD==z or UUL==z or DDR==z or URU==z) return true;
    else return false;
  }

  void zombie_diago(Pos LD, Pos UL, Pos DR, Pos RU, Pos DLD, Pos UUL, Pos DDR, Pos URU, Pos z, Dir& dir) {

    int id_in_cell1 = cell(DLD).id;
    int id_in_cell2 = cell(UUL).id;
    int id_in_cell3 = cell(DDR).id;
    int id_in_cell4 = cell(URU).id;
    int id_in_cell5 = cell(LD).id;
    int id_in_cell6 = cell(UL).id;
    int id_in_cell7 = cell(DR).id;
    int id_in_cell8 = cell(RU).id;

    if(DLD==z and pos_ok(DLD) and cell(DLD).type != Waste and unit(id_in_cell1).player!=me()) dir =  Left;
    else if(UUL==z and pos_ok(UUL) and cell(UUL).type != Waste and unit(id_in_cell2).player!=me()) dir = Left;
    else if(DDR==z and pos_ok(DDR) and cell(DDR).type != Waste and unit(id_in_cell3).player!=me()) dir = Right;
    else if(URU==z and pos_ok(URU) and cell(URU).type != Waste and unit(id_in_cell4).player!=me()) dir = Right;
    else if(LD==z and pos_ok(LD) and cell(LD).type != Waste and unit(id_in_cell5).player!=me()) dir = Right;
    else if(UL==z and pos_ok(UL) and cell(UL).type != Waste and unit(id_in_cell6).player!=me()) dir = Right;
    else if(DR==z and pos_ok(DR) and cell(DR).type != Waste and unit(id_in_cell7).player!=me()) dir = Left;
    else if(RU==z and pos_ok(RU) and cell(RU).type != Waste and unit(id_in_cell8).player!=me()) dir = Left;
  }


  /**
   * Play method, invoked once per each round.
   */
  
  virtual void play () {
    
    // If nearly out of time, do nothing.
    double st = status(me());
    if (st >= 0.9) return;

    // Getting the alive units
    vector<int> alive = alive_units(me());
    vector<int> noprio;

    for (int id1 : alive) { //prioritat
     Pos pos_act_p = unit(id1).pos;
     bool found = false;

     for(auto d : dirs) {
      int id_in_cell = cell(pos_act_p+d).id;
      if(pos_ok(pos_act_p+d) and cell(pos_act_p+d).type != Waste) {
        if (id_in_cell != -1 and unit(id_in_cell).type == Alive and unit(id_in_cell).player!=me()) {
          found = true;
          move(id1,d);
        }
      }
     }
    if (not found) noprio.push_back(id1);
    }

    for (int id2 : noprio) { //no prioritat
      Pos pos_act_p = unit(id2).pos;
      Pos pos_zombie;
      Pos pos_menjar;
      Pos pos_dummy;
      Pos pos_dead;
      
      Dir dir_menjar;
      Dir dir_zombie=Up;//ini a qualsevos
      Dir dir_dummy=Up;//ini a qualsevol
      Dir dir_dead;
      vector<vector<Pos>> prev_menjar(board_rows(),vector<Pos>(board_cols(),Pos(-1,-1)));
      vector<vector<Pos>> prev_zombie(board_rows(),vector<Pos>(board_cols(),Pos(-1,-1)));
      vector<vector<Pos>> prev_dummy(board_rows(),vector<Pos>(board_cols(),Pos(-1,-1)));
      vector<vector<Pos>> prev_dead(board_rows(),vector<Pos>(board_cols(),Pos(-1,-1)));
      int d_menjar = bfs_menjar(pos_act_p,pos_menjar,prev_menjar);
      int d_zombie = bfs_zombie(pos_act_p,pos_zombie,prev_zombie); 
      int d_dummy = bfs_dummy(pos_act_p,pos_dummy,prev_dummy);   
      int rfz;
      int d_dead = bfs_dead(pos_act_p,pos_dead,prev_dead,rfz);

      vector<Pos> diagz = {pos_act_p + LD, pos_act_p + UL, pos_act_p + DR, pos_act_p + RU};
      Dir zd=Up;
      vector<Pos> diagz2 = {pos_act_p + Down + LD, pos_act_p + Up + UL, pos_act_p + Down + DR, pos_act_p + Up + RU};

//strateg

      if(d_dummy==1) {
        dir_dummy = funcio(pos_act_p,pos_dummy,prev_dummy);
        move(id2,dir_dummy);
      }

      else if(d_zombie<=d_menjar) {
        if(hay_zombie_diago(diagz[0],diagz[1],diagz[2],diagz[3],diagz2[0],diagz2[1],diagz2[2],diagz2[3],pos_zombie)) {
          zombie_diago(diagz[0],diagz[1],diagz[2],diagz[3],diagz2[0],diagz2[1],diagz2[2],diagz2[3],pos_zombie,zd);
          move(id2,zd);
        }
        else {
          dir_zombie = funcio(pos_act_p,pos_zombie,prev_zombie);
          move(id2,dir_zombie);
        }
      }

      else if(d_menjar<d_zombie) {
        dir_menjar = funcio(pos_act_p,pos_menjar,prev_menjar);
        move(id2,dir_menjar);
      }
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
