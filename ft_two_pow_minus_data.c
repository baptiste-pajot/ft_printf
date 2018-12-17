/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_two_pow_minus_data.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 11:22:26 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:55:41 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_two_pow_minus_data5(int pow)
{
	if (pow > -1000)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000011830521861667747109727515975180265316521821839047721774031627016"
		"442078286329192012182539543906581092999160526085549907512784594031828"
		"150041092547804494060697592130703573274941490644281620724162665675421"
		"681994613662757519416135169475726273842104032165358658546000092188059"
		"390807714054593515317928833982284000395525215823035233958313492699963"
		"466918841769394842569091185503838593998412246468251372748143195451505"
		"809857882156164285347853577744888714056104354791659240017734742476497"
		"275861458688607654317495987742760889324112559103884326361476047387672"
		"008450659022089158949184697572519184857828961066061879137123469263315"
		"2008056640625");
	return (ft_two_pow_minus_data6());
}

static char		*ft_two_pow_minus_data4(int pow)
{
	if (pow > -900)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000014996968138956309548176444"
		"376280653535399616962391082979373344476177108558521903027709681283974"
		"148362424896476280058609953836415026314702291613758053752177801321562"
		"234290889582784131143026191509064156102728265681863641420905320135883"
		"054919705226867848059808204770499736953783347532521383772530548085895"
		"021769327351906735809209030100953963740850911360851242346222913434255"
		"993052086995135374751010768669185995188448391668224655840558730056688"
		"974198720403184262340529763691064411109576482780831011292732918868470"
		"931087464627362582092473530792631208896636962890625");
	return (ft_two_pow_minus_data5(pow));
}

static char		*ft_two_pow_minus_data3(int pow)
{
	if (pow > -800)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000019010915662951598235150724058351031092648712063735190324"
		"417460575658542492774722035572014970526218632026106295032981886747782"
		"624437886235035446245838525279781878470810317345929123576953847952803"
		"421761182550402077743821601989638561515255154238266579842690004225363"
		"586214007024208070520183533509822927164194849825351101422492970569249"
		"064885554038921400627919266619185306132626564929716679905185033997599"
		"098684948025630300586762031760911737080761105831219759387806789163732"
		"90121555328369140625");
	return (ft_two_pow_minus_data4(pow));
}

static char		*ft_two_pow_minus_data2(int pow)
{
	if (pow > -600)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000030549363634996046820519793932136176997894027405"
		"723266638936139092812916265247204577018572351080152282568751526935904"
		"671553178534278042839697351331142009178896307244205337728522220355888"
		"195318837008165086679301794879136633899370525163649789227021200352450"
		"820912190874482021196014946372110934030798550767828365183620409339937"
		"395998276770114898681640625");
	else if (pow > -700)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000024099198651028841"
		"177407500347125089364310049545098979718302999771588038528602610374756"
		"815976954150789041343723288125124578606269849931065815063037552014867"
		"642226143264298011181762014850975069917952106112908826203946886018771"
		"711342653872262412524281755817072898752781021220687871462877849296611"
		"267513631801626978909993656439467896719583112506183576351032584342330"
		"4911856806746609828417948762080413871444761753082275390625");
	return (ft_two_pow_minus_data3(pow));
}

char			*ft_two_pow_minus_data(int pow)
{
	if (pow < 0 && pow > -100)
		return ("0.5");
	else if (pow > -200)
		return ("0.00000000000000000000000000000078886090522101180541172856528"
		"27862296732064351090230047702789306640625");
	else if (pow > -300)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"062230152778611417071440640537801242405902521687211671331011166147896"
		"988340353834411839448231257136169569665895551224821247160434722900390"
		"625");
	else if (pow > -400)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000049090934652977265530957719549862756429"
		"752155124994495651115491171871052547217158564600978840373319522771835"
		"715651318785131679186104247189028075148241089634522531054644598619285"
		"3894181098439730703830718994140625");
	else if (pow > -500)
		return ("0.00000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000000000000000000000000000000000038725919"
		"148493182728180306332863518475702191920487908654877629413444163480976"
		"859648626822342770145969080575425075544675393708363989923503155223180"
		"506533504920024360652705308027384320383731747540908093676464549424001"
		"81270162578968846816261130394654088604511343874037265777587890625");
	else
		return (ft_two_pow_minus_data2(pow));
}
