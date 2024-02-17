#ifndef CPP07_EX00_whatever_H_
# define CPP07_EX00_whatever_H_

template<class T> void	swap(T& v1, T& v2) {
	T	tmp = v1;
	v1 = v2;
	v2 = tmp;
}

template<class T> T&	min(T& v1, T& v2) {
	return (v1 < v2) ? v1 : v2;
}

template<class T> T&	max(T& v1, T& v2) {
	return (v1 <= v2) ? v2 : v1;
}

#endif
