#include "wide_trie.h"
#include <stdio.h>

void free_node(wide_node * n)
{
	for (int i = 0; i < NUM_CHARS; i++) {
		if (n->children[i])
			free_node(n->children[i]);
	}
	free(n);
}

void free_trie(wide_trie * t)
{
	free_node(t->root);
	for (int i = 0; i < t->val_count; i++)
		free(t->vals[i]);
	free(t->vals);
	free(t);
}

int main (int argc, char ** argv)
{
	wide_trie * trie = init_wide();
	insert("dog", "furry dumb", trie);
	insert("do", "or do not, there is no trie", trie);
	insert("tamra", "hot wife", trie);
	insert("dogsbody", "person who performs boring menial tasks", trie);
	insert("ke$ha", "popstar", trie);
	insert("!@#$", "crusses", trie);
	insert("!@#$", "cusses", trie);
	insert("waz crakin", "not much", trie);
	const char* arr[] = {"kS4zIqBjYlqb1r", "1OVpvSPgjRZZ3M", "l2YuCUynMeE41q", "bSh03Jp4cnK7li", "NzyvOUXcpeHFcQ", "lfK4qsnYoTC2wp", "J2PGybpxjecEXI", "j0i58HisOB79an", "wweX3QQbxJF7zZ", "rZEJHoPN6LJyZt", "Sna0GTDb2cJMhN", "2rEnWBkZ6KXExP", "3WfeFnR9hPi9B8", "vT2f1guNaMmiWG", "MGuh3e79jTYTOR", "UffBrpbT3e4ZYG", "JChqAfkg8NHosN", "KiUysjtcTqwPsa", "arXzTlPi8aY5iy", "ugtDGvJAuOpvEH", "VtQaA7ekqj8AOt", "5SwRrIuX8Tf0Sv", "VLgVYyFFzonENy", "amj7pWbTRD82Rm", "KeOD4t6wbeJixc", "U1USv29c2vCuLo", "uWvceCpzv3juXS", "q3XXI5wm9P5N3J", "7lXJSCytvH6hNY", "NjAvvX6eMChWpu", "JCW21TgQFk8z07", "1Re9MZxkPLgV4h", "tVruJFSrx29es5", "QDLYSnUQpBH62O", "KfjQEFmj06u0Hg", "TZxpHMB8qwQ82e", "mW5XDBaXs4Zxwb", "ORab0Wx7D9F3Sy", "VekxhVDTy5hYuM", "HlMf7NvkkhyyhY", "lVBS464cyyTlpH", "hmYVs3qeOhKpSo", "6TBHJ0yNE5evUH", "RZrTWnjeyiOZ2M", "iiVyXISDrSjPZz", "568zHvifhmwxk3", "liFsBv3Kf3aC6z", "GeFvulYQ3M6gGh", "BHfypmap1UH3h2", "kiBW8CqzRNno6g", "OAPfSNaEEIIUwy", "oc3VZES4IihmVj", "MYsJkymST0pIFj", "O0sX5pPfEESVxz", "JP1S7QV9CQBNiR", "uxPtXfRhBmvoSF", "nAq87xQOpkVH4k", "wM6BRoexcBGizl", "rlr1qr68eEKmAY", "qjB19fV97MVs7s", "UKz5vJaMtzQqx4", "kfVO76AT7ZWqHx", "IqGr9A8ULJ1Y0G", "SI7AVrl9wneqUq", "CG006zuIwHXArr", "NEEZFXojVei7Lq", "O7tSeH4lTNKfm6", "xyFtp2a3goXZo4", "5FAmiPtMRh3l5T", "aynCLXfXiK0sCl", "kHQP6PXOr1PC7o", "G3oFCOlVXwWxh1", "JcbOTnnIbli5PQ", "4OcZLc8RmZFxaq", "bmVMCaOCw7QfsS", "VnHJXvsWMZ9ixO", "UmuzFtS1VE3cF4", "Oc6xoqfMRc7QSn", "gmkR2EnO8jw5Jk", "vZIUNbz0HVCm9c", "YHNv9X5O7SnLz2", "wgDKfp68h5ly7n", "NhKkyHvqFHsbwp", "cV4QzzHe3uBxbM", "ZcZbQp8gufRIAq", "PqQYv6nzRPK1hS", "TjsTpiISyc51kB", "vLG6AyphfO9MaG", "j1WPgNmGC3C6PV", "CGJZ1MH7GlHUGK", "vO9pGjiY3UcIcP", "cwacRFvEs3Ngmc", "WnAfeuBVCwJ8Qn", "OiA8W70yF88uY3", "3SkTkHUChz4ZUh", "QXu6Azb2HoX2GU", "V0WClR1uZwBWuH", "HlS7wUMeHbIhfy", "2gi4tIYttfPlP0", "4e4hLvmXXt9FJ6","2WwNgT9ApD5P39","5XK1QiDOWHk09Z","eNsD0S5m2TXgc0","mneJWW8ACbXbpT","UaaiYBDneHEgRS","zb8YSgBxWCRhlV","leHuuIK95gKPj1","5jw6cNMo4YwmqK","cJFEp7V4lZJAC1","kon651HQnK4iiT","fnmpTvw3Sz4C6Y","AuzSrmnvYwCK6G","Nr5WIxyhJfU4SN","yGR6DsjRs6U3Pn","wHFtpzeqrc5ncM","txDezrKwZT89TU","bxF4v88I797F4b","CFJ4SOuBce6rt1","O675QcmEl7JWTe","EjxVcpr2yy4ow3","oUHKTPQZzWNSsz","b9e8ncrVQttEZz","o0yvIy0DarJF25","eBcyfJ7ARYC12F","L7F7MqB2YB53v8","fTmcq43Ng2Vlue","ow2nBGfAqzsQHh","UzKZun6qjrQy2O","zXUmB1eEQxGk5L","3cDzmuITTzIDvC","aQNyRugVgHTE6M","ePgshMv3fkXoIY","4nzQ8zXZ2PKCKf","PaRC5e2v5yqUmB","Qyo3nLMR8hnwE1","mRCFpWWVQr0IVo","veEcc6wtZP2pNI","OL3opw3hmjnXPa","YbNfvptFRUcIkY","l1QCVY83WbrTho","x2yCtrO3QOCB3q","9r0IBx8blornUp","GPF94lkYvQkoBx","T09tuC9u5Btixb","m6kZ5vAkvHoJ59","nNSqWbBV3TLONg","YctPxeK5cB0JSn","KRl874Mst17oiy","jEKnZWwILQEvAr","Exx1EwvOiQrRN1","QSzN8SenyQ4uUS","bM9GLKaAAS0JSJ","I5xXIxYfTV1FWm","LSG2ClvVhqHWSC","wC54eM00IxGOX5","IxDnSv4GjG8kLc","F0OHVFeytrlZ5b","g09VpbVgSNl5hZ","1fHrkG5DJIFpiS","qp2lQHXEXPgvfR","LBlp7n32FyfcOg","BnIrK8v1x9Sri1","eVDrbT3KcjHryA","fApb71eLgJc8oJ","szNYUpEo3rPTRF","Sju8a0SuWO1Uv6","wLu7bzufmQgqDN","mbQpVSahErZjRW","zmZAQLaYvpVpIy","aBYlXM5tUh2KQc","3CYXFM92m6OM7N","68ZySKBG6X0vm9","N5C20WElpVqNVR","t6E9noEnclnuDF","wtPVTBeMRnE77S","NBTGOAoSehSDjY","wCRklcXI7SBfCE","0CE82jeiXpsGFr","iw0cEACg9hKIJE","Bme3VpSvZM3v6B","2cyCTL9YVr0CQW","HREBOgb808Hzi7","0opQqwaN1E7uiu","6h0cyZTD5WYDUC","BOEQEJ2R7fpeO6","yALbl5QJlj2Tbs","7ySo51miy7acXF","PaOFRNt16LJSE6","svkFhhazgErfcK","zxnp5NPBe2NBtl","Ql6iYv2YTZ5UaY","g96nVGeBvXtonx","LpwCxuUZmS9w1C","m5NExKs0J0msp3","K7jXPQt61GAzR4","WskkuSxByiKqek","sXJQDUM18rS1L5","o9Ck2GzDE9ggpI","X0lHN5PrNPDmhN","afPKNIhHgC1gov","nP0L5xI9sgowWz","ofiAUoBkopxbtY","t1PJJU8KyOGPxv","NqTK04RlZ0wsEM","c0c2lYVoWavjNq","rQ6DfFP8XsFCpG","Zxx8RaNe34yvW7","XlDp3po5PMqtbm","qXuv8uUS23DXsL","xO9LtDjs2p4irH","k8qkaiwNU69xAX","ztmr5XuOxKoXu8","NWUhTAwptBRTny","BXgRNDNG1828l9","4i9znuItnowGZM","RtgeRFH15QYEJq","JWih9sRPzH9bNx","lV2jwAQILoa6gE","ggOH4mYRgt91uZ","9sSAj8fA3uVhHs","K7uBrAUqiCoUnx","WlTWhgWorMaSOu","YEfkHpOf6vCSu2","JFzla8zCMfMZlH","0INtizW1SLnIMs","DCPGDYDBImUxI3","wKHkiHhzz5PRzo","yyksuv7Rmjjkll","8NhlMKsblgGOXf","0WVeRp5Rh5fCzX","DpCwLOEefhfhWk","MkjHJP4pq6RXfF","kbtWzch9SRPnT7","z8qeVPwuAkDNDD","HJ231erx7xF0uz","hcITYsIEZT6bhi","PfW0gfSQBN4ALK","1vKFnbWLgj3ufp","yMcNgU6oX2MYgM","UR7QApLOEcfQEG","Fwic6qKRqP0PMm","yvtEsEyEya1KqC","ncOLrfIhOKvhaa","DqwPor4BseSInV","Wu6sI956BcHc6k","7GfFMtFbnRGWkZ","aMe9Dav7K8wbR7","E4FGtzjMDLXJaM","HnGAj1L4wnwfbT","wkp8CjKpIsIz2R","hZ0knXExBMREPp","ZqVf5q30fuhMJq","Tq7B1LBvr3ObpZ","6Gh2PQXLLnsg0r","IXg4eIUSN1w6Mw","g96cG7OaOimxOX","KoIEwVzbLqrBFV","COuDlWeoeJUCmp","3RIpbXGJhWMymG","h23c4pV1bCnYrg","3LaOZVFlTsXENB","zm56lEBZ9P5Y3Q","qRVaU058kFzeN7","iU0b3YKanKAjt3","JUANG8eA33r7vh","xRjhZ1g19pNFNE","2nvpRkLKejvfN4","8T0sRmF2yAwQUf","SAOLRHGlWQuGD9","a2t7VfsjrV6ptX","Ntz8SsiBc0hAK1","1vigQfeOcoXFNV","nUmQ0lBBsyAmrP","mgmNKUaYcKhj4X","blHpS06zLWVua4","SiWVhamHSyHWJv","zEFzKLFzrmvXLj","WwhLzuOWiyw7il","w8C25kIXIcchta","Zx0jb6nbpS4YNL","wb9SlGNPlRDg3R","vtDQ2XXX3UAcyJ","Q8vM6sm7aDpPyS","AgbtDurpBJF5MS","0iJohHbQ0MBbWv","hF5DlrnGFiY0hF","V87hB7hqMsFqJR","YrcmLRjb6xAn7o","mqHXaKp3VvgsPV","UB47S8nzNpoiqk","Skif5lXqKxkmq4","h4kuBuOPA26xZD","k30q2pq3Cg8hBF","MrYDlUMgfErScf","T9GvuEQyDQwuyw","MnQ6FzwWXMN0xT","7sOAREWK3wWMJy","8k0BJU58W5V3gg","tBfBxYSf7vgu3u","cAGWfx5pOoGMFm","aG83OO5fzjOHSm","jOB3BSN1iTPDhk","hmrSvxDbz3XUHy","uFObUoijNK8fBn","fihGuwi6z8LAbt","WCLJfsTFIS7j90","62RzQyOGxEoTZf","HUDtgYHnBFbZfN","5sFQqLjqZyCVqZ","8b5wu9GtDu4UMm","OC5DmozNimcKOz","Iq8HW6qMAKbi7U","PbwjRoTUYH3XKJ","MV5EK9wVGWYOIm","YSYflulFSFerUM","IpUVbxFQLcCMun","yvy2QILskFKrfJ","JokIGUyKq71gnN","qUuHc3cERjhDLg","u1vDagvfGZARth","vCDOjXsQcCN95l","rKAol7j3kHFZZg","1V3qZG1WvQmeVA","sloDqDBr4UDBji","nLintMs0j2uL5C","AmbW124aX7cgtt","iaCRyXtNqYOiCk","0suqTiZ4QEQcgw","P5CUG4bSgV5sLP","yCzHBVovT8QsU3","x3G5DxqDMSwxJh","9HUzY31nVl6RHF","ZVvJpOhe4Y07P9","oknU6iQTbEtrSv","QbCawagOQ5rXUA","DXaWohiliYozZi","4LZxnvg26BezBT","HfBagT8OLCeSMS","BBFbYwAeMBpi67","qcjlgbxIbZQsia","52Y0TMeHQNiAvY","Wqez92wBhYUOzL","aHlgEoKUhUtJpK","IbAVCYQjvhF7Tr","nITlgYlWq9BsqD","PWqa5HVEQjVcKX","TqFfAoZoumqfra","XQ5slHi6QnDvhE","s3l1MqyS2M3X41","JqiatAogNJs8xf","RfxWkIZEvJ7yz7","0sBoalxXoo3lA3","F542zzDIg1tGnM","ZaivyVxk3HYrKN","VemA5RcrsTXBD1","qJTYBWUjwsQYUv","CgioZkA9XU33mT","K0ilsrpwfSu7XD","iayKzi71RBTeu1","NxTqlFZTS0oCZM","L0qw7uLuIh8Jqk","laguWjsXTHxgB5","eM9RKDcqyjfL76","gRwV5opBtx4X65","8sWgCtPCS6WRg6","KkUU0KlCKZx3ZB","h9bi6mZuXZQEwo","03Sr0CawweVe78","1GJB7XLIq2ycsP","BznyB2xNcZcGVb","1siK8kStNBro9m","i88RvSepSUrUKv","76yIfU8g5Ctote","c73bHCOe0lUfen","QTqw1jSkxU6iCt","C5CaJjQkIpMJYR","t44DPMV4kLlMy6","47WUJmiN5UckPo","uGGFytYpcXefye","ODWWjQMsTgEWTy","vM9E8lpfDhfFKB","zEbSysD5COZfOn","kwnSVCGmAmRCfN","L9qS7943Oz8Q2H","soDPM7E4xAlNyM","S2ScHw42Hq0MeM","3gzlaPTeaHXNZq","tQiRheeYkjw89a","8NrD6mXgIMzA6R","934euUEC1O5ZsG","FjGDMhXbuMQ53E","Y0VhwgFoY7is9G","gxIC3fYMAaAkiV","WJhM4X6a5hJoc4","syTDEPXsUpUGcb","uIIKZ7j19gL0Nr","4pXzFrR2hAsylZ","0CWUUvEKllfhlF","ufJzeZm8EmgVCg","8pNHfuKA9ShtyD","gGnkrv9ik2579v","FEMoFwDjpza7tX","yeo94rsXa7VZt4","xt8kbnOqwMcpOr","EnI4PsJ3iubWay","CWqCXno4uBm8N3","oEOjUyMynDRmNE","AbI0rw9jO8o3oD","CoX7WPgRfuU27G","5SsLpojZyUwkWt","4p5HFKYvUDqx8m","RmQgxcjm3yh3bN","rRIZUaDsRTNZlA","88CkQyATOllZJ9","Dakyzl3DfPEyWz","0zlHKbDhZfVjeb","6nBII3HXuxsvOf","R4cKwwnEDOT8O2","EJS1TCsx63jnFR","1TB0kmLzeqWYgR","x0XC6zr8TAbTDK","qFGEiGWjn8BHjs","nW1mhYxTlKPUZc","97naNGGJMeSb03","PG1IxM2z4mwJqM","BOFxM0ROyKJ4N4","5bjz2ixjzGLkVP","Rz4CK6cIZix19J","C49g5fBtv11AYL","ZFRBq6XsLeEb3b","fCYkPPOaT26sCS","elipT0nf6qMfQE","AV7J9jN6V0kCNI","f6j6xLsWN2q8zA","nqWDlksgXyuxeI","B9mN9h6Vlh0R6e","IpLc4wxRAwRDTl","IjS4mzoZ5iNCXJ","56A0ASsJmqyxzq","wKtUCjGm278gsA","YqMViH4pYpnNOY","LUazFislQZDf1H","NRW75mbLiOQv8J","futJ3Pk3poGcoW","hSmqwrq3HKtgNi","RpiKDX3LitMUut","fVeMvOXq9yE89h","1JvCDrLDksLeA2","xNG4F7ZKJs62y9","ARzzcYsCQoR45S","Io3xKXuoyAnCvh","FODlY1kAvSC40N","VUSyY5W8ZkT0wT","IJm8WlIOGhgAWY","jBnEM266ERzDi4","P4jz7ZLOZlr51Q","17GOnhZiKpyKBE","6yvuDY7w69NXkD","TMPK7vNecpgolr","fpFryzW2P0Ejwc","cU7yUQz3XGfYag","hNlyYTfoXrmp5Y","Saj3xbNoW1B7KC","MnAYaTPtcE5bvi","8JwwsaxZYmehJO","U16Dyp7M36DJy2","fjPHtZIwJFEozE","LGTQcwwUIjqS4n","WMNYVvJO3GCNIZ","nRp0U1utRgFBC6","wDzHjNrDA4GEBC","LVH6CoQqXBywcw","2TgHEkj6hqR4S5","is5zfBw0xxvJaU","mGwZ21kC5KQgyC","JgUUjIUnPhfxe8","TerFQTxjgjmROk","wkTNmJSRkoGGqz","mGnCsqLrapavi4","8bkU4MJbF41TJo","1B04LVLuDJW0Ue","GThjgwLs57Jmb6","x2EPO3mCvo7hIk","lvubmi2OaqxzaE","xICVeBySIOr4RK","nXACtIuTEZYqeF","wCFgocSyRRiGWv","rWUor0oT0VTPwr","cLDrZqZKiRr7aN","BEC8o84WrfCk9I","nOaPKhcvJrYOqY","j2XOPEN2l7BQMw","VqjSahFLARNLx0","6kyacoaxDqHcu3","cyzlbhp6piwglS","7PpCO88xEXt46j","HbXCIlloIwxVHl","vAoXaiZhPzenZq","oxbQeGbSlGI8SO","sF4s1VGSV0KGwi","PCBMjLEEQK1IuE","7Fo5qtunY97Z6c","ewP581avPDR1Fl","DPl7Y5cbAQxmE5","zNmnj1R0VoIiFs","aQnqErHY6XtXXv","NyFNiMTs2jLnbu","jV6DlbI1prsvgt","kQWSaz52D9qEPs","S7EFy73vhVZEuZ","STahr1SfubaiIB","RH3gnNoo2JV0pb","L9Wy2iPOnUvrsE","LRtWk6l0EcAexC","m769WzfcNFUD97","wQIQjn0YlFBC1H","xtAsXYpORR0Eeb","skhCJRs7u4ystD","thor5uZn7imUGG","OHwTt4ffTNoyrj","ATrFKUpPEoy58V","DDTE65RrZLb3xw","vgXm6wBnaakIbs","PlrAfHl5bugSc5","7S63NfxqxGSvFn","G1DmYcVsUjJiqE","CjOMUKQbnMhreB","RLzkQF62WwnvUe","0cUQlhocezALiS","Z3HkWIAmFKGtO2","YYrveNXUiTZxYI","r4r6mGRoChboUY","gjgmGvnGWzlY13","LWOBnuJT9RtfBR","aT3hlbggvG6ZD2","EDiqC1Fen6qbUW","xSncTfED1Jqhmg","3zxVSuSfAgDo31","7PhHCX02xylroK","uV5pQuEfLz5fHB","oC01D1n5YphmfZ","4t75kuG12GK5qk","P1s52C38A1UTcz","iX56mWviNj7w7X","KO02i8TplH7GLj","tgnZB6bVYtrjam","fW1WzRfnEl5G7p","og9xXPVjv8WBub","5RWvf1iESE4a4h","KN8mmyO4G5SEcp","UQC17zDqjBy6OH","FW1xhVDpC4ZVHC","qN9VOoP8qm1CSb","SbhGwwtfCAptmb","RtN4q81pstVa3h","EquNNQuaFPE4UR","UJiNTvio6leKMg","sKFbKWDYJzPgqn","0ZaI4cUUGF1uzz","OtyYvYAXCL7FKI","tT0urLnipc4ruZ","5SQRg7MHMB9JqM","DDzg2VNwMFBonn","mr70xATLT7BRri","Z6ugCBZbPNptve","GGk9nXUugasqfi","nv0f6hXFIVSzrh","FNSmNRXDup41jL","uQxJMt4OHBaeif","Tc9L88GupA7IiW","mSI7pcHtQr0JtK","BjYWcflOOgtqDt","XIMGVf8LiGuP2S","yBFEHiqzMyAZBF","8j0ZbRAY8PEQFE","Gw9NSiDW3u5lTX","o15LStxGV8MuuC","BJS6OcN8va2SWG","6ytxaXeDOKAn7t","f3GGqpGOXu6nNs","jS1cQCZyzi23vc","UtOExik6TpVrfW","okVVe19K6gYqea","un4RQA2rSIJka3","Rt2YB1eNcrAnc5","QwwDo2TMIKMF0u","BGKiuEoq5Uuu47","C27VTjng6YBp8G","bAb59tWZb1XvA8","hemgoUM2PclFva","myZIUMeu0LUOul","ZIWB3BmaCL6zzM","vg0e3BUEgSx6iy","96a7Kh7SWBQ8kF","DJbrAyFtoqYlRr","teMNtOj9Nsh80F","np8OyKxwIA2xUL","baByPYW4ty3B1s","E449CZ3MnJD1Ux","MMzy5MwomlRoQS","M66z213awx0Bmv","5rjxSJ6r2lr5ZN","TibCUGngKzIBwm","zZuwOTT8HpAPRW","beY5JLnzhJuQkb","Bz4gw7IDWZAM7q","Hee4LFHZfHr63U","K1QAl0qqW0a7bZ","gzZYsSzC5zr32e","0lsVfsMzJiIpPu","CLja25qT0rRnwg","YWnZmGRNmP7bMs","CPXv i7mp4u9onqI$d2L$K9aoIQLaSbvQwaSrER4cK9PmtJq1ycXzOzmYmhcrrUuQI?UEI4Su9SzzR7l3G?mNvLI", "gqG", "jRxzkyW*uJJj6?YC$q2Je*ksjOx", "Y#B27URY4swd77TU33", "TIzi6f27cyHuDDupf5DGhobqW", "rQGzbrJR3Z!Xa*MB#nRmB8qPsOmxYLCcESi6vIw9M08CAN 9y 5gq NhXm", "", "y3YE", "AAhUcoYmlI62MwM75$3e1wMjL?8M", "3n36xx2vEez0Rm LlATZ7r9c?0WyDSqY2KndbRocqcE jgRLN!v!mhDbiq8?JARjn&9!T8AjX5uL*I50BErMyw", "JrtnRS8NdL551", "SLJqoI6IDf$rJqe2 IXy5oeyo*bRryW!eteQ#qpO2U9zw1g8Y", "tyuMHvMosYK&mVkQtP&tenK8Yi3", "j*h!jvKvf1B# dhdT y&JEmk?QJiZij4V$y77S0QzUOzk9hh BdqA#Aa?Z3y8wImU*VNMfjztKIMWINa$LQGNMfPBBwU8fjbA1MR", "RcnszBD!b9kjAD8U82wq#2GKUFjQ3uuYqt2IoN", "o1bb&T1", "NZQ4iGwaHW#uSDP!*90pT40om", "8eW1unobnh*nmDb8xcDbohhi21arr", "LaerRo2iGxM7", "d4W0xS8JFl?tNPfzwhndU*v*fjWGYIA hLb&6Py1TK", "WKiY9gjbNnOKyubJ*Pv9kmchVe4B4$A1qEMoit*NYn!b3X1CAPC??W67BZjZXm*tO0V8WcYR2AXut1$zdnMUB6P8&542uyahfpX2O2GUwKE!96$QSxsO2ZSCzFOQrUGtEg P", "imFxyjDufyKCAo", "s$?wP8A4&5", "pAztrP9A6Zvz &rUNRTFDmkPZ6jqZejhfwiohWCqZYaY&nBMU$p4ZKH00SO&mh", "Id2y9dT!mDRvonnZqTp&Y$!9cy7MrmmI", "hqd9", "G4N6U3yLe3jeq#Ja", "JWCWrqS5Bm*V MU", "QE?#xfdHE73YA?L EWzXuObn bEOIWv*FS#AI9*o10C0!sfSgQ&XKl*h&ufKixPXaqPJx4j5F6o", "vEhQPy7a7wRRY2!zhvzNdLImQ I8IK6Z3gdeyLS5WPCZIXMKC3 qiw680PXWmt4Z", "EM", "6jvX", "L!qd0AD*8r43ltQMzrdFS2VViPh4", "ZwlCJ##L6m7o0#8l", "6pN?", "HHjGB9xkXWX?paha$m0ZCIS8ViGtT6&zStrdj&jmImW1WO !wrkM", "a3C", "WNmWoPOpX#$dh", "vn*2b3D7!hTNUonNXCc&5UBcTMR3JKGpL 7C9EhvS&3b*kxmNHuMgHi", "ZMS", "MbnPP!bQVWGiUcogZQ#92KDKZ?", "#!5?!zQ1QE*L4!fvFC3Y5Pw0TcP1il6D7K8ENZ5kW5iNNNAI7qDzShgeNj7HVJr!NXvxUh HODLlYVMs4zG 3dSl&tj aUV&ayiZyNpq", "t0UMnGKa0*oOZqzlnsb6RHLk!OQt7Yp3GND#WdZFkImAdHVlAZ3D0TC", "kgDq13wwj52P", "HdvJ5NJoe!XgBPHkW!fa0 Z", "EY*rXl$7cmz01aYVvP&Fh7sPzD3KUDfwjJq#Q6Gm&0oIg&KzmBFGu4A", "$Y?g ob?*oup9Una&cfvKAioBx CZO5nQ$DO11VZwT9?Pud", "5hxK*Qg", "b", "j9P8Odt?JdlJIi0oESZD#XV7*DnG0zL76mHHv*F$t5UgGb!", "BKNyTHzzDD8RlNAIeGlB9", "Ee", "mQk", "a*kYMZLfi8?D", "HS&*WI", "6", "q6Ex", "Tr3", "zupW2dgitUY$hc 1!44B21pw5sm", "Mf", "PgPrrFoUoctMttwAJ#", "f5", "0ZKJ9?ZHfZBbfHsDVqX&PoILB0b0", "cFv*1ygb hgi !pIf55O1&PrN*CAXC3", "*h", "HlMBH5jPbNh8#4R#1e!BmRDXkosurqdtButfh", "X5l71w8JRJvO*TD6OlylOf", "Kfey!xu8WJ0IU", "mWXOn0cWJ", "&eegK4gID1n4psCBV$t", "lN#1AlG!n59QNTwxtgNqcr6at3wkrHFaFbiN9Cjg7dVvJPnE$ShKHxgwkJ6h*!oYbcDIz2&Vge5 vAfJ 5QwbbOV$Oh1Igb49hqS", "sBt2J9z$d?3I", "RoAQp!xdXD9jcQK", "nTfq3SA6SeduNUerRsd8#3", "KKVy0i!yL6f$WRBYvMtuWj$12Sgz*tc&gGHfwVe&xtKnwl", "6mEn7Mjuo?x*wHbieJzUUybs7Nu2d", "hMq5Ecz$", "kR*9OOlBo1mcQ905MrnAfp!MwLHzEKBAvYpAR$C7A1Y&MF&DiVxOiRKf8txS7pELzQF#bgC4f 4U?i8OymSVKp45c?X4s?PBxiaSaWO$Qpb?BJGqui8g9rufxx7yDxHHs?qt9URC4#D?hxWxOsHRbSOJ*5Di5TGAkwHo?tmGWfsJtkEprDiB4YbM lHoqrs#!&U4Z6!A$", "DHL3hW76i1Xi1pzJ$QQr1b&E700d9AETcz#9bN#4RAmQNZJGGXRor!VvZAKKo1ogq*J*ETjEzwbg", "6hoW4EUTloXb$B?Iy", "nZP271oXvgYf8 AQq3ViAk#V7dvlm4cdfidDbn?WlpX", "0", "y8kp&g1tpW6$FxngO?0*#j8XVEnJWiChLvSe*1*zS", "4xf", "6$$Q?$1M6josoZL8&MPJMPB6Ad83T897YiqvcRJMl4jI9D0UfHW CP7", "iGivxE9NT rUZvA", "8KpH&*v?Koj2vfcItw8", "Bff", "qKM2C6ExRlbahNoGk#n9#gryY", "aLsx1AU8QeFRg640qXw1mS ", "D?JVL&rPE6NDdz&7xeVELRhNpYNia&u7XJYgTiJxpsmFJr*Fp", "Ma2PBkpW", "Y8yWmOFXOvQXKA6l2E", "csj&Grq3e$lWmCn3*PVeU! j2jT", "K8JlpYBLY&WN", "Yh", "U6CtOX*S6IPhRrIN!cbR1h9Ja753RG3", "9*Zq4D8TSrK", "K5JGG8gBb rku9ign", "?RV NGca9Ny$PV&dXseoMjD4038ayy&mKiRPV", "2 $Hgziz3$qeP3tK", "?rBfuyC9yJG3BXF5 8p9N*BKynvt", "usnShCYPx6y", "8Y5wyB5anUUGuwBvFhf jIj2Tv", "m9Gffxe3L&?8EdVA5iM4AiamSmZ6 6HKE1VtPa", "giKHPGGhl", "Yi3bia7U1IR5DWj9wYId9KBQD$T$k209lYgLyYVAkTocnZNwH&D", "kQ4G&4rY0Xx!tSCN4IYsMrrA$jNgPCeQ30qfJb", "3Mj5Y6H?6ooATa#8l$XbwIa$c#V?!c3q9k", "&KwJfVN!rCuRdDAEJwN8fBU5hJt*We6AyaS*FibiPFILBlluYO", "ks5l6BbC#2&rO2$Iq7*RoLC3pcl6sknYeDyDDDBojcA7OEboQ28wsllflDxUWbM?v84q2I36zj kyIDdKs?Q7kOF15Mw7B*h 8qg$EqjsbG#1K3KOrlLEledAOxCezW", "S1", "CUrtabSVy3YQ9$SEorOjWJx&hmzr1j5 OEy1 LfcjFGCOVt33tDSDDNppnY93Sy!l34vsTUuthEFX#DMaK5ilipryPGdYlu835xpk$Q?19e86Fx", " jfy4OI?79m6Vs7EeGWO*WDZcLTrwQ4i5FrhsSz", "25?U 55XCWjeO3rFH9LcEKeF$Rlc&d57jW!jFyz!1w kkY9#bQGyUIKzCmw7g1$n#3unLAxyCb", "67hLYI!fK5l7?eYOk", "NOFNJrlgvB#Gjd0TKl8N2h", "pP0$ faLPw9qqMXjC&UY#x37PQyugReKbwnDJng!e!k8", "Cw*wb2NRvi5&LMg20evngZDAu", "n#jwtaW55AS90yMQSO", "bNqrDeb", "XlE6gwZhoV4ZvvIbpfco8YWIWiF50N?#kNc#ULXLEiSX570D&qRW&1VYZ4", "Ccv2X#d2PvFJLjrHI", "M", "eEqDV58m121NOCGnYOuHpWXF", "ZDTIYuUIY5J0rwC7j2e&goL1G*9WA9AICZF?&G0RvFsEr?m4AcQ6uN8PKdz0MumCnfYLooH*r69rh*", "0#ds d7rLe2npNnehTwgok3", "2n2R4mRYC9aQwBAPe61kbWpzz $ARCCnzT?CrYok puo u"};
	for (int i = 0; i < sizeof(arr)/sizeof(char*); i++)
		insert(arr[i], "randstr", trie);

	lookup_wide("dog", trie);
	lookup_wide("do", trie);
	lookup_wide("tamra", trie);
	lookup_wide("dogsbody", trie);
	lookup_wide("ke$ha", trie);
	lookup_wide("!@#$", trie);
	lookup_wide("!@#$", trie);
	lookup_wide("waz crakin", trie);

	for (int i = 0; i < sizeof(arr)/sizeof(char*); i++) {
		if (strcmp(lookup_wide(arr[i], trie), "randstr"))
			printf("ERROR: lookup %s returned %s\n", arr[i], lookup_wide(arr[i], trie));
	}

	char * key = malloc (256 * sizeof(char));
	scanf("%s", key);

	printf("%s: %s\n", key, lookup_wide(key, trie));
	free_trie(trie);
	free(key);
}
