/*
    This file is part of the FElt finite element analysis package.
    Copyright (C) 1993-2000 Jason I. Gobat and Darren C. Atkinson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/************************************************************************
 * File:	definition.c						*
 *									*
 * Description:	This file contains the public and private function and	*
 *		variable definitions for adding, removing, and looking	*
 *		up element definitions.					*
 ************************************************************************/

# include "problem.h"
# include "definition.h"
# include "setaux.hpp"

int
AddDefinition(Definition definition)
{
    return !problem.definition_set.insert(definition).second;
}

int 
RemoveDefinition(Definition definition)
{
    return problem.definition_set.erase(definition) != 1;
}

Definition
LookupDefinition(const char *name)
{
    return SetSearch(problem.definition_set, name);
}
