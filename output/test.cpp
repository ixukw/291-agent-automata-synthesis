#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "test.h"
namespace ANONYMOUS{

void main__Wrapper() {
  _main();
}
void main__WrapperNospec() {}
void _main() {
  int _tt0[23] = {3, 1, 1, 2, 2, 0, 0, 0, 3, 3, 3, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0};
  int*  true_actions= new int [23]; CopyArr<int >(true_actions,_tt0, 23, 23);
  int  l_s1=0;
  move_left(0, 0, l_s1);
  int  l=0;
  l = l_s1;
  int  r_s3=0;
  move_right(0, 0, r_s3);
  int  r=0;
  r = r_s3;
  int  u_s5=0;
  move_up(2, 0, u_s5);
  int  u=0;
  u = u_s5;
  int  d_s7=0;
  move_down(0, 0, d_s7);
  int  d=0;
  d = d_s7;
  assert ((((((((l_s1) <= (3)) && ((r_s3) > (3))) && ((u_s5) > (3))) && ((d_s7) > (2))) || (((((r_s3) <= (3)) && ((l_s1) > (3))) && ((u_s5) > (3))) && ((d_s7) > (2)))) || (((((u_s5) <= (3)) && ((l_s1) > (3))) && ((r_s3) > (3))) && ((d_s7) > (2)))) || (((((d_s7) <= (2)) && ((l_s1) > (3))) && ((r_s3) > (3))) && ((u_s5) > (3))));;
  int  next=0;
  if ((l_s1) <= (3)) {
    next = 0;
  } else {
    if ((r_s3) <= (3)) {
      next = 1;
    } else {
      if ((u_s5) <= (3)) {
        next = 2;
      } else {
        if ((d_s7) <= (2)) {
          next = 3;
        }
      }
    }
  }
  assert ((next) == ((true_actions[0])));;
  for (int  i=1;(i) < (23);i = i + 1){
    int  l_s9=0;
    move_left(l, next, l_s9);
    l = l_s9;
    int  r_s11=0;
    move_right(r, next, r_s11);
    r = r_s11;
    int  u_s13=0;
    move_up(u, next, u_s13);
    u = u_s13;
    int  d_s15=0;
    move_down(d, next, d_s15);
    d = d_s15;
    assert ((((((((l_s9) <= (3)) && ((r_s11) > (3))) && ((u_s13) > (3))) && ((d_s15) > (2))) || (((((r_s11) <= (3)) && ((l_s9) > (3))) && ((u_s13) > (3))) && ((d_s15) > (2)))) || (((((u_s13) <= (3)) && ((l_s9) > (3))) && ((r_s11) > (3))) && ((d_s15) > (2)))) || (((((d_s15) <= (2)) && ((l_s9) > (3))) && ((r_s11) > (3))) && ((u_s13) > (3))));;
    if ((l_s9) <= (3)) {
      next = 0;
    } else {
      if ((r_s11) <= (3)) {
        next = 1;
      } else {
        if ((u_s13) <= (3)) {
          next = 2;
        } else {
          if ((d_s15) <= (2)) {
            next = 3;
          }
        }
      }
    }
    assert ((next) == ((true_actions[i])));;
  }
  delete[] true_actions;
}
void move_left(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 4;
    } else {
      if ((move) == (1)) {
        _out = 2;
      } else {
        if ((move) == (2)) {
          _out = 9;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  } else {
    if ((state) == (1)) {
      if ((move) == (0)) {
        _out = 1;
      } else {
        if ((move) == (1)) {
          _out = 0;
        } else {
          if ((move) == (2)) {
            _out = 2;
          } else {
            assert ((move) == (3));;
            _out = 0;
          }
        }
      }
    } else {
      if ((state) == (2)) {
        if ((move) == (0)) {
          _out = 3;
        } else {
          if ((move) == (1)) {
            _out = 1;
          } else {
            if ((move) == (2)) {
              _out = 9;
            } else {
              assert ((move) == (3));;
              _out = 1;
            }
          }
        }
      } else {
        if ((state) == (3)) {
          if ((move) == (0)) {
            _out = 0;
          } else {
            if ((move) == (1)) {
              _out = 4;
            } else {
              if ((move) == (2)) {
                _out = 24;
              } else {
                assert ((move) == (3));;
                _out = 2;
              }
            }
          }
        } else {
          if ((state) == (4)) {
            if ((move) == (0)) {
              _out = 8;
            } else {
              if ((move) == (1)) {
                _out = 6;
              } else {
                if ((move) == (2)) {
                  _out = 2;
                } else {
                  assert ((move) == (3));;
                  _out = 4;
                }
              }
            }
          } else {
            if ((state) == (5)) {
              if ((move) == (0)) {
                _out = 15;
              } else {
                if ((move) == (1)) {
                  _out = 24;
                } else {
                  if ((move) == (2)) {
                    _out = 1;
                  } else {
                    assert ((move) == (3));;
                    _out = 2;
                  }
                }
              }
            } else {
              if ((state) == (6)) {
                if ((move) == (0)) {
                  _out = 24;
                } else {
                  if ((move) == (1)) {
                    _out = 7;
                  } else {
                    if ((move) == (2)) {
                      _out = 8;
                    } else {
                      assert ((move) == (3));;
                      _out = 1;
                    }
                  }
                }
              } else {
                if ((state) == (7)) {
                  if ((move) == (0)) {
                    _out = 8;
                  } else {
                    if ((move) == (1)) {
                      _out = 4;
                    } else {
                      if ((move) == (2)) {
                        _out = 4;
                      } else {
                        assert ((move) == (3));;
                        _out = 1;
                      }
                    }
                  }
                } else {
                  if ((state) == (8)) {
                    if ((move) == (0)) {
                      _out = 0;
                    } else {
                      if ((move) == (1)) {
                        _out = 0;
                      } else {
                        if ((move) == (2)) {
                          _out = 9;
                        } else {
                          assert ((move) == (3));;
                          _out = 2;
                        }
                      }
                    }
                  } else {
                    assert ((state) == (9));;
                    if ((move) == (0)) {
                      _out = 0;
                    } else {
                      if ((move) == (1)) {
                        _out = 0;
                      } else {
                        if ((move) == (2)) {
                          _out = 5;
                        } else {
                          assert ((move) == (3));;
                          _out = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //assert ((_out) < (10));;
  return;
}
void move_right(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 5;
    } else {
      if ((move) == (1)) {
        _out = 3;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  } else {
    if ((state) == (1)) {
      if ((move) == (0)) {
        _out = 2;
      } else {
        if ((move) == (1)) {
          _out = 2;
        } else {
          if ((move) == (2)) {
            _out = 12;
          } else {
            assert ((move) == (3));;
            _out = 4;
          }
        }
      }
    } else {
      if ((state) == (2)) {
        if ((move) == (0)) {
          _out = 0;
        } else {
          if ((move) == (1)) {
            _out = 0;
          } else {
            if ((move) == (2)) {
              _out = 4;
            } else {
              assert ((move) == (3));;
              _out = 0;
            }
          }
        }
      } else {
        if ((state) == (3)) {
          if ((move) == (0)) {
            _out = 1;
          } else {
            if ((move) == (1)) {
              _out = 6;
            } else {
              if ((move) == (2)) {
                _out = 0;
              } else {
                assert ((move) == (3));;
                _out = 3;
              }
            }
          }
        } else {
          if ((state) == (4)) {
            if ((move) == (0)) {
              _out = 8;
            } else {
              if ((move) == (1)) {
                _out = 15;
              } else {
                if ((move) == (2)) {
                  _out = 6;
                } else {
                  assert ((move) == (3));;
                  _out = 1;
                }
              }
            }
          } else {
            if ((state) == (5)) {
              if ((move) == (0)) {
                _out = 4;
              } else {
                if ((move) == (1)) {
                  _out = 1;
                } else {
                  if ((move) == (2)) {
                    _out = 0;
                  } else {
                    assert ((move) == (3));;
                    _out = 0;
                  }
                }
              }
            } else {
              if ((state) == (6)) {
                if ((move) == (0)) {
                  _out = 5;
                } else {
                  if ((move) == (1)) {
                    _out = 0;
                  } else {
                    if ((move) == (2)) {
                      _out = 4;
                    } else {
                      assert ((move) == (3));;
                      _out = 4;
                    }
                  }
                }
              } else {
                if ((state) == (7)) {
                  if ((move) == (0)) {
                    _out = 16;
                  } else {
                    if ((move) == (1)) {
                      _out = 1;
                    } else {
                      if ((move) == (2)) {
                        _out = 2;
                      } else {
                        assert ((move) == (3));;
                        _out = 0;
                      }
                    }
                  }
                } else {
                  if ((state) == (8)) {
                    if ((move) == (0)) {
                      _out = 1;
                    } else {
                      if ((move) == (1)) {
                        _out = 0;
                      } else {
                        if ((move) == (2)) {
                          _out = 12;
                        } else {
                          assert ((move) == (3));;
                          _out = 6;
                        }
                      }
                    }
                  } else {
                    assert ((state) == (9));;
                    if ((move) == (0)) {
                      _out = 22;
                    } else {
                      if ((move) == (1)) {
                        _out = 0;
                      } else {
                        if ((move) == (2)) {
                          _out = 21;
                        } else {
                          assert ((move) == (3));;
                          _out = 12;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //assert ((_out) < (10));;
  return;
}
void move_up(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 20;
      } else {
        if ((move) == (2)) {
          _out = 2;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  } else {
    if ((state) == (1)) {
      if ((move) == (0)) {
        _out = 0;
      } else {
        if ((move) == (1)) {
          _out = 8;
        } else {
          if ((move) == (2)) {
            _out = 3;
          } else {
            assert ((move) == (3));;
            _out = 16;
          }
        }
      }
    } else {
      if ((state) == (2)) {
        if ((move) == (0)) {
          _out = 4;
        } else {
          if ((move) == (1)) {
            _out = 24;
          } else {
            if ((move) == (2)) {
              _out = 1;
            } else {
              assert ((move) == (3));;
              _out = 4;
            }
          }
        }
      } else {
        if ((state) == (3)) {
          if ((move) == (0)) {
            _out = 2;
          } else {
            if ((move) == (1)) {
              _out = 0;
            } else {
              if ((move) == (2)) {
                _out = 8;
              } else {
                assert ((move) == (3));;
                _out = 0;
              }
            }
          }
        } else {
          if ((state) == (4)) {
            if ((move) == (0)) {
              _out = 6;
            } else {
              if ((move) == (1)) {
                _out = 0;
              } else {
                if ((move) == (2)) {
                  _out = 5;
                } else {
                  assert ((move) == (3));;
                  _out = 9;
                }
              }
            }
          } else {
            if ((state) == (5)) {
              if ((move) == (0)) {
                _out = 0;
              } else {
                if ((move) == (1)) {
                  _out = 4;
                } else {
                  if ((move) == (2)) {
                    _out = 0;
                  } else {
                    assert ((move) == (3));;
                    _out = 7;
                  }
                }
              }
            } else {
              if ((state) == (6)) {
                if ((move) == (0)) {
                  _out = 5;
                } else {
                  if ((move) == (1)) {
                    _out = 5;
                  } else {
                    if ((move) == (2)) {
                      _out = 8;
                    } else {
                      assert ((move) == (3));;
                      _out = 2;
                    }
                  }
                }
              } else {
                if ((state) == (7)) {
                  if ((move) == (0)) {
                    _out = 5;
                  } else {
                    if ((move) == (1)) {
                      _out = 6;
                    } else {
                      if ((move) == (2)) {
                        _out = 0;
                      } else {
                        assert ((move) == (3));;
                        _out = 5;
                      }
                    }
                  }
                } else {
                  if ((state) == (8)) {
                    if ((move) == (0)) {
                      _out = 4;
                    } else {
                      if ((move) == (1)) {
                        _out = 1;
                      } else {
                        if ((move) == (2)) {
                          _out = 10;
                        } else {
                          assert ((move) == (3));;
                          _out = 0;
                        }
                      }
                    }
                  } else {
                    assert ((state) == (9));;
                    if ((move) == (0)) {
                      _out = 1;
                    } else {
                      if ((move) == (1)) {
                        _out = 8;
                      } else {
                        if ((move) == (2)) {
                          _out = 9;
                        } else {
                          assert ((move) == (3));;
                          _out = 16;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //assert ((_out) < (10));;
  return;
}
void move_down(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 1;
    } else {
      if ((move) == (1)) {
        _out = 0;
      } else {
        if ((move) == (2)) {
          _out = 6;
        } else {
          assert ((move) == (3));;
          _out = 2;
        }
      }
    }
  } else {
    if ((state) == (1)) {
      if ((move) == (0)) {
        _out = 0;
      } else {
        if ((move) == (1)) {
          _out = 0;
        } else {
          if ((move) == (2)) {
            _out = 0;
          } else {
            assert ((move) == (3));;
            _out = 3;
          }
        }
      }
    } else {
      if ((state) == (2)) {
        if ((move) == (0)) {
          _out = 0;
        } else {
          if ((move) == (1)) {
            _out = 0;
          } else {
            if ((move) == (2)) {
              _out = 0;
            } else {
              assert ((move) == (3));;
              _out = 1;
            }
          }
        }
      } else {
        if ((state) == (3)) {
          if ((move) == (0)) {
            _out = 4;
          } else {
            if ((move) == (1)) {
              _out = 6;
            } else {
              if ((move) == (2)) {
                _out = 4;
              } else {
                assert ((move) == (3));;
                _out = 0;
              }
            }
          }
        } else {
          if ((state) == (4)) {
            if ((move) == (0)) {
              _out = 0;
            } else {
              if ((move) == (1)) {
                _out = 27;
              } else {
                if ((move) == (2)) {
                  _out = 7;
                } else {
                  assert ((move) == (3));;
                  _out = 14;
                }
              }
            }
          } else {
            if ((state) == (5)) {
              if ((move) == (0)) {
                _out = 9;
              } else {
                if ((move) == (1)) {
                  _out = 4;
                } else {
                  if ((move) == (2)) {
                    _out = 3;
                  } else {
                    assert ((move) == (3));;
                    _out = 3;
                  }
                }
              }
            } else {
              if ((state) == (6)) {
                if ((move) == (0)) {
                  _out = 31;
                } else {
                  if ((move) == (1)) {
                    _out = 3;
                  } else {
                    if ((move) == (2)) {
                      _out = 0;
                    } else {
                      assert ((move) == (3));;
                      _out = 16;
                    }
                  }
                }
              } else {
                if ((state) == (7)) {
                  if ((move) == (0)) {
                    _out = 3;
                  } else {
                    if ((move) == (1)) {
                      _out = 6;
                    } else {
                      if ((move) == (2)) {
                        _out = 9;
                      } else {
                        assert ((move) == (3));;
                        _out = 2;
                      }
                    }
                  }
                } else {
                  if ((state) == (8)) {
                    if ((move) == (0)) {
                      _out = 0;
                    } else {
                      if ((move) == (1)) {
                        _out = 27;
                      } else {
                        if ((move) == (2)) {
                          _out = 4;
                        } else {
                          assert ((move) == (3));;
                          _out = 1;
                        }
                      }
                    }
                  } else {
                    assert ((state) == (9));;
                    if ((move) == (0)) {
                      _out = 9;
                    } else {
                      if ((move) == (1)) {
                        _out = 0;
                      } else {
                        if ((move) == (2)) {
                          _out = 5;
                        } else {
                          assert ((move) == (3));;
                          _out = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //assert ((_out) < (10));;
  return;
}

}
