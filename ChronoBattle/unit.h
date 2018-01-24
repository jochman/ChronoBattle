#pragma once

class unit {
public:
	unit(const int& hp_max, const int& sp_max, const int& atk, const int& def, const CString& name, const CString bmpPath = L"res/default.bmp");
	virtual int hp_max() const;
	virtual int hp_current() const;
	virtual int sp_max() const;
	virtual int sp_current() const;
	int cAtk() const;
	virtual int atk() const;
	int cDef() const;
	virtual int def() const;
	virtual CString name() const;

	virtual void set_name(CString);
	
	virtual void set_hp(int);
	virtual void set_hp_max(int);
	virtual void set_sp(int);
	virtual void set_sp_max(int);
	virtual void set_atk(int);
	virtual void set_def(int);

	virtual void inc_hp_max(int);
	virtual void dec_hp_max(int);
	virtual void inc_sp_max(int);
	virtual void dec_sp_max(int);
	virtual void inc_atk(int);
	virtual void dec_atk(int);
	virtual void inc_def(int);
	virtual void dec_def(int);



	
	virtual void decrease_sp(int);

	
	virtual void reborn();

	
	virtual CString heal(int hp);

	virtual CString attack(unit*);
	virtual CString attack(unit&);

	virtual HBITMAP& hBmp();

	virtual void defend_debuff(int turns = 2);
	virtual void general_debuff(int turns = 2);
	virtual int get_defend_debuff();
	virtual int get_general_debuff();
	

protected:
	virtual int hurt(const int&, unit*);
	virtual int hurt(const int&, unit&);
	virtual bool def_flag() const;
	virtual bool debuff_flag() const;
	virtual void def_cycle();
	virtual void debuff_cycle();
	virtual CString sp_attack(unit* oppo, bool & act, double multiplier, CString sp_name, int cost);

private:
	int hp_max_;
	int hp_current_;
	int sp_max_;
	int sp_current_;
	int atk_;
	int def_;

	CString name_;

	CString bmp_path_;
	HBITMAP hBmp_;

	bool def_flag_;
	bool debuff_flag_;

	int defend_turn_counter_;
	int debuff_turn_counter_;
};