/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS
// clang-format off
ComputeStyle(bond/local,ComputeBondLocal);
// clang-format on
#else

#ifndef LMP_COMPUTE_BOND_LOCAL_H
#define LMP_COMPUTE_BOND_LOCAL_H

#include "compute.h"

namespace LAMMPS_NS {

class ComputeBondLocal : public Compute {
 public:
  ComputeBondLocal(class LAMMPS *, int, char **);
  ~ComputeBondLocal() override;
  void init() override;
  void compute_local() override;
  int pack_forward_comm(int, int *, double *, int, int *) override;
  void unpack_forward_comm(int, int, double *) override;
  double memory_usage() override;

 private:
  int nvalues, nvar, ncount, setflag;

  int singleflag, velflag, ghostvelflag, initflag;
  int dvar;
  int *bstyle, *bindex, *vvar;
  char *dstr;
  char **vstr;

  int nmax;
  double *vlocal;
  double **alocal;

  int compute_bonds(int);
  void reallocate(int);
};

}    // namespace LAMMPS_NS

#endif
#endif
