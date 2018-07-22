with open("sol.cpp", "w") as f:
	f.write("#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]\n#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << \" \"\n\nint main(){\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\
		\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\tvector_input(a, n);\n\n\treturn 0;\n}")