/**
 * @file ivb.hotel.reviews
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> splits(string k) {
  vector<string> ans;

  string s = "";
  for (auto c : k) {
    if (c == '_') ans.push_back(s), s = "";
    else
      s += c;
  }
  ans.push_back(s);
  return ans;
}

struct trie {
 public:
  trie *children[26];
  bool leaf;
  void append(string w);
  int rank(string w);
};

void trie::append(string w) {
  trie *r = this;
  for (auto c : w) {
    if (!r->children[c - 97]) r->children[c - 97] = new trie();
    r = r->children[c - 97];
  }
  r->leaf = 1;
}

int trie::rank(string w) {
  trie *r = this;
  for (auto c : w) {
    if (!r->children[c - 97]) return 0;
    r = r->children[c - 97];
  }
  return r->leaf;
}

vector<int> solve(string A, vector<string> &B) {
  trie *t = new trie();
  for (auto w : splits(A)) {
    t->append(w);
  }

  int n = B.size(), rank[n];
  memset(rank, 0, sizeof rank);

  for (int i = 0; i < n; ++i) {
    auto ws = splits(B[i]);
    for (auto w : ws) {
      rank[i] += t->rank(w);
    }
  }

  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    q.push({rank[i], -i});
  }

  vector<int> ans;

  while(!q.empty()) {
    ans.push_back(-q.top().second), q.pop();
  }

  return ans;
}

int main() {
  vector<string> b = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
  auto ans = solve("qghu_eay_nl_dxfi_cvsc_gg_wk_nqdu_wf_fozv_rtk_pr_p_g_rp_rvys_mwcy_y_c_pev_kef_mz_imkk_svw_r_nzk_cxf_tl_gyp_fad_oo_fxz_co_juv_vabo_gpo_ylf_bnpl_vrvi_ya_yeh_q_qrqp_x_j_loov_o_u_wh_s_cb_coks_zkva_xdkn_yj_h_ixjs_nkk_f_ux_zr_bmnm_q_oke_ly_nk_aug_qrcd_iute_ojw_yyz_vs_m_sa_lfvg_b_aaov_zy_nt_kdcp_s_te_j_hdi_co_zc_fw_qi_tv_wvxh", b);
  for(auto k: ans) cout << k << endl;
  return 0;
}