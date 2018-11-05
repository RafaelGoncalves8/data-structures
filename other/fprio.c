void
sobe_no_heap(p_fp fprio, int k)
{
  while (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave)
  {
    troca(&fprio->v[k], &fprio->v[PAI(k)]);
    k = PAI(k);
  }
}

void
desce_no_heap(p_fp fprio, int k)
{
  while (k < fprio->tam && (fprio->v[F_ESQ(k)].chave > fprio->v[k].chave || fprio->v[F_DIR].chave > fprio->v[k].chave))
  {
    if (fprio->v[F_ESQ(k)].chave > fprio->v[k].chave)
    {
      troca(&fprio->v[k], &fprio->v[F_ESQ]);
      k = F_ESQ(k);
    } 
    else (fprio->v[F_DIR].chave > fprio->v[k].chave)
    {
      troca(&fprio->v[k], &fprio->v[F_DIR(k)]);
      k = F_DIR(k);
  }
}
