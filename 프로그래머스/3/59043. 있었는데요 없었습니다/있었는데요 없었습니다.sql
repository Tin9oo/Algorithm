-- 코드를 입력하세요
# SELECT ANIMAL_INS.ANIMAL_ID, ANIMAL_INS.NAME
# FROM ANIMAL_INS
#     JOIN ANIMAL_OUTS
#     ON ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
# WHERE ANIMAL_INS.DATETIME > ANIMAL_OUTS.DATETIME
# ORDER BY ANIMAL_INS.DATETIME;















select a.animal_id, a.name
from animal_ins a
join animal_outs b
    on a.animal_id = b.animal_id
where a.datetime >= b.datetime
order by a.datetime
;