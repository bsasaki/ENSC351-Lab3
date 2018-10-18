myMap reduce(std::vector<myMap> v1) {
	/* create_pair- Section 4.1.3
	   Purpose: creates a single key-value pair given a list of pairs with the same keys
	   Input: list of key-value pairs, which should have the same key
	   Output: a single key-value pair with correct value
	*/

	myMap m1;
	m1.person = v1[0].person;
	for (int i = 0; i < v1[0].friendlist.size(); i++) {
		if (v1[1].friendlist.find(v1[0].friendlist[i])) {
			m1.friendlist += v1[0].friendlist[i];
		}
	}
	m1.friendlist = v1.size();
	return m1;
}
