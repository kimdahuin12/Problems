function solution(id_list, report, k) {
    let answer = [];
    let reported = new Set();
    let mapCnt = new Map();
    let mapAnswer = new Map();
    let arrReported = new Array();
    let arrReport = new Array();
    let stopId = new Array();
    //중복 신고 처리
    report.map((r)=>reported.add(r)); //중복 제거
    reported.forEach((r) => arrReport.push(r));
    reported.forEach((r) => arrReported.push(r.split(' ')[1]));
    
    id_list.map((id)=>mapCnt.set(id, 0));
    arrReported.map((rep)=>mapCnt.set(rep, mapCnt.get(rep)+1));
    mapCnt.forEach((value, key)=> { if(value>=k)stopId.push(key); });
    
    id_list.map((id)=>mapAnswer.set(id, 0));
    for(let r of arrReport){
        if(stopId.indexOf(r.split(' ')[1]) != -1){
            mapAnswer.set(r.split(' ')[0], mapAnswer.get(r.split(' ')[0])+1);
        }
    }
    mapAnswer.forEach((v)=>answer.push(v));
    console.log(mapAnswer);
    return answer;
}
