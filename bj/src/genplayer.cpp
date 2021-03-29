#include "genplayer.cpp"

virtual bool GenericPlayer::isHitting() {
	return false;
}

bool GenericPlayer::IsBoosted() {
	return (GetValue() > 21);
}

void GenericPlayer::Boost() {
	cout << m_name << " busts!\n";
}
