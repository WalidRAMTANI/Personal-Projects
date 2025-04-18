import React from 'react'

type Props = {
    children: React.ReactNode
}
export function Feedwrapper({children}: Props) {
  return (
    <div className='flex-1 relative top-0 pb-10 flex flex-col gap-y-3'>
        {children}
    </div>
  )
}  