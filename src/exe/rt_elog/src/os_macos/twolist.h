/* 
 * Proview   $Id: twolist.h,v 1.2 2005-09-01 14:57:48 claes Exp $
 * Copyright (C) 2005 SSAB Oxel�sund AB.
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, either version 2 of 
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with the program, if not, write to the Free Software 
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* Specifikation av tv�v�gslista -- twolist.h */

#ifndef TWOLISTH
#define TWOLISTH

#ifndef rt_elog_h
#include "rt_elog.h"
#endif

typedef sKey datatyp;       /* Exempelvis */

typedef
struct twolink
{
   enum {head, lank} kind;
   struct twolink *befo, *next;
   datatyp data;
} headtyp, linktyp;

void newhead(headtyp **hpp);
/* Skapar en ny tom lista */

void newlink(linktyp **lpp);
/* Skapar en ny tom l�nk */

void putlink(datatyp d, linktyp *lp);
/* S�tter in data i en l�nk */

datatyp getlink(linktyp *lp);
/* Returnerar data fr�n l�nk */

void inlast(linktyp *lp, headtyp *hp);
/* S�tter in l�nken sist i listan */

void infirst(linktyp *lp, headtyp *hp);
/* S�tter in l�nken f�rst i listan */

void inpred(linktyp *lp, linktyp *ep);
/* S�tter in f�rsta l�nken f�re den andra */

void insucc(linktyp *lp, linktyp *ep);
/* S�tter in f�rsta l�nken efter den andra */

void insort(linktyp *lp, headtyp *hp, int (*is_less)(datatyp d1, datatyp d2));
/* S�tter in l�nken sorterad enligt is_less */

linktyp *firstlink(headtyp *hp);
/* Returnerar pekare till f�rsta l�nken i listan */

linktyp *lastlink(headtyp *hp);
/* Returnerar pekare till sista l�nken i listan */

linktyp *predlink(linktyp *lp);
/* Returnerar pekare till l�nken f�re */

linktyp *succlink(linktyp *lp);
/* Returnerar pekare till l�nken efter */

int is_link(linktyp *lp);
/* Returnerar 1 om l�nk annars 0 */

int empty(headtyp *hp);
/* Returnerar 1 om listan tom annars 0 */

int nrlinks(headtyp *hp);
/* Returnerar antalet l�nkar i listan */

void outlist(linktyp *lp);
/* Tar bort l�nken fr�n listan */

void elimlink(linktyp **lpp);
/* Tar bort, avallokerar och NULL-st�ller l�nken */

void clearhead(headtyp *hp);
/* Tar bort alla l�nkar fr�n listan */

void elimhead(headtyp **hpp);
/* Eliminerar och NULL-st�ller listan */

#endif